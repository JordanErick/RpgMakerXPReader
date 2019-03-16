#include "reader/reader.hpp"

rpg::Reader::Reader(const std::vector<u8>& bytes)
: mIndex{0}
, mBytes{bytes}
, mSymbolCache{}
, mObjectCache{}
{
    readVersion();
}

rpg::Any rpg::Reader::parse()
{
    auto type = read<u8>();

    switch (type)
    {
        case '0': // Nil
            return Any{};
        case 'F': // Bool
            return Any{ Type::Bool, new bool{false} };
        case 'T': // Bool
            return Any{ Type::Bool, new bool{true} };
        case 'i': // Fixnum
            return readFixnum();
        case '"': // String
            return readString();
        case ':': // Symbol
            return readSymbol();
        case ';': // Symlink
            return readSymlink();
        case 'u': // UserDef
            return readUserDef();
        case '[': // Array
            return readArray();
        case '{': // Hash
            return readHash();
        case 'o': // Object
            return readObject();
        case '@': // Link
            return readLink();
        default:
            throw std::runtime_error(fmt::format("Unsupported type specifier: {}", type));
    }
}

void rpg::Reader::readVersion()
{
    auto major = read<u8>();
    auto minor = read<u8>();

    if (major != 4 || minor != 8)
        throw std::runtime_error(fmt::format("Invalid marshal version: {}.{]", major, minor));
}

rpg::Any rpg::Reader::readFixnum()
{
    auto byte = read<i8>();

    if (byte == 0) return { Type::Int, new i32{0} };

    if (byte > 0)
    {
        if (4 < byte && byte < 128) return { Type::Int, new i32{ byte - 5 } };

        if (byte > static_cast<i8>(sizeof(i32)))
            throw std::runtime_error("Too big int");

        i32 value = 0;
        for (i32 i = 0; i < byte; i++)
            value |= static_cast<i32>(read<u8>()) << (8 * i);

        return { Type::Int, new i32{ value } };
    }
    else
    {
        if (-129 < byte && byte < -4) return { Type::Int, new i32{ byte + 5 } };

        byte = -byte;

        if (byte > static_cast<i8>(sizeof(i32)))
            throw std::runtime_error("too big int");

        i32 value = -1;
        for (i32 i = 0; i < byte; i++)
        {
            value &= ~(static_cast<i32>(0xff) << (8 * i));
            value |= static_cast<i32>(read<u8>()) << (8 * i);
        }

        return { Type::Int, new i32{ value } };
    }
}

rpg::Any rpg::Reader::readString()
{
    i32 length = *readFixnum().as<i32>();

    auto* value = new std::string{};
    value->reserve(length);

    for (i32 i = 0; i < length; i++)
        *value += read<i8>();

    auto any = Any{ Type::String, value };
    mObjectCache.push_back(any);

    return any;
}

rpg::Any rpg::Reader::readSymbol()
{
    i32 length = *readFixnum().as<i32>();

    auto* value = new std::string{};
    value->reserve(length);

    for (i32 i = 0; i < length; i++)
        *value += read<i8>();

    if (std::find(mSymbolCache.begin(), mSymbolCache.end(), *value) == mSymbolCache.end())
        mSymbolCache.push_back(*value);

    return Any{ Type::String, value };
}

rpg::Any rpg::Reader::readSymlink()
{
    i32 cacheIndex = *readFixnum().as<i32>();
    return { Type::String, new std::string{mSymbolCache[cacheIndex]} };
}

rpg::Any rpg::Reader::readUserDef()
{
    auto name = parse();

    if (name.type() != Type::String)
        throw std::runtime_error(fmt::format("Invalid name type: {}", name.type()));

    i32 size = *readFixnum().as<i32>();

    if (*name.as<std::string>() == "Color")
    {
        auto red = read<double>();
        auto green = read<double>();
        auto blue = read<double>();
        auto alpha = read<double>();

        auto any = Any{ Type::Color, new Color{red, green, blue, alpha} };
        mObjectCache.push_back(any);

    return any;
    }
    else if (*name.as<std::string>() == "Table")
    {
        i32 count = (size - 5 * sizeof(i32)) / sizeof(i16);

        auto dimensions = read<i32>();
        auto xSize = read<i32>();
        auto ySize = read<i32>();
        auto zSize = read<i32>();
        auto totalSize = read<i32>();

        std::vector<i16> data;
        data.reserve(count);

        for (i32 i = 0; i < count; i++)
            data.push_back(read<i16>());

        auto any = Any{ Type::Table, new Table{dimensions, xSize, ySize, zSize, totalSize, data} };
        mObjectCache.push_back(any);

        return any;
    }
    else if (*name.as<std::string>() == "Tone")
    {
        auto red = read<double>();
        auto green = read<double>();
        auto blue = read<double>();
        auto grey = read<double>();

        auto any = Any{ Type::Tone, new Tone{red, green, blue, grey} };
        mObjectCache.push_back(any);

        return any;
    }
    else
        throw std::runtime_error(fmt::format("Unsupported user defined class: {}", *name.as<std::string>()));
}

rpg::Any rpg::Reader::readArray()
{
    i32 length = *readFixnum().as<i32>();

    auto* array = new Array{};

    for (i32 i = 0; i < length; i++)
        array->push_back(parse());

    auto any = Any{ Type::Array, array };
    mObjectCache.push_back(any);

    return any;
}

rpg::Any rpg::Reader::readHash()
{
    auto* hash = new Hash{};

    i32 entriesCount = *readFixnum().as<i32>();

    for (i32 i = 0; i < entriesCount; i++)
    {
        auto key = parse();
        auto value = parse();
        (*hash)[key] = value;
    }

    auto any = Any{ Type::Hash, hash };
    mObjectCache.push_back(any);

    return any;
}

rpg::Any rpg::Reader::readObject()
{
    auto className = parse();

    if (className.type() != Type::String)
        throw std::runtime_error(fmt::format("Invalid class name type: {}", className.type()));

    auto* object = new Object{ *className.as<std::string>() };

    auto variablesCount = *readFixnum().as<i32>();

    for (i32 i = 0; i < variablesCount; i++)
    {
        auto key = parse();

        if(key.type() != Type::String)
            throw std::runtime_error(fmt::format("Invalid key type: {}", key.type()));

        auto value = parse();
        (*object)[*key.as<std::string>()] = value;
    }

    auto any = Any{ Type::Object, object };
    mObjectCache.push_back(any);

    return any;
}

rpg::Any rpg::Reader::readLink()
{
    // TODO: Implement this and make sure we have valid object cache
    i32 cacheIndex = *readFixnum().as<i32>();
    auto* tmp = new std::string{ fmt::format("LINK_{}", cacheIndex) };
    return Any{ Type::String, tmp };
}

std::string whitespace(int count)
{
    return std::string(count, ' ');
}

void writeToString(std::string& str, const rpg::Any& any, int indent)
{
    switch (any.type())
    {
    case rpg::Type::Array:
    {
        auto* array = any.as<rpg::Array>();

        if (array->empty())
        {
            str += "Array[]";
        }
        else
        {
            str += "Array[\n";

            for (size_t i = 0; i < array->size(); i++)
            {
                str += whitespace(indent + 2) + fmt::format("'{}' = ", i);
                writeToString(str, array->at(i), indent + 2);
                str += "\n";
            }

            str += whitespace(indent) + "]\n";
        }

    } break;

    case rpg::Type::Bool:
        str += fmt::format("{}", *any.as<bool>());
        break;

    case rpg::Type::Int:
        str += fmt::format("{}", *any.as<i32>());
        break;

    case rpg::Type::Hash:
    {
        auto* hash = any.as<rpg::Hash>();

        str += "Hash{\n";

        for (const auto& element : *hash)
        {
            str += whitespace(indent + 2) + "'";
            writeToString(str, element.first, 0);
            str += "' -> ";

            writeToString(str, element.second, indent + 2);
            str += "\n";
        }

        str += whitespace(indent) + "}";
    } break;

    case rpg::Type::Null:
        str += fmt::format("nil");
        break;

    case rpg::Type::Object:
    {
        auto* object = any.as<rpg::Object>();

        str += fmt::format("{}(\n", object->className());

        for (const auto& element : *object)
        {
            str += whitespace(indent + 2) + fmt::format("'{}' = ", element.first);
            writeToString(str, element.second, indent + 2);
            str += "\n";
        }

        str += whitespace(indent) + ")\n";

    } break;

    case rpg::Type::String:
        str += fmt::format("\"{}\"", *any.as<std::string>());
        break;

    case rpg::Type::Color:
    {
        auto* color = any.as<rpg::Color>();

        str += "Color[\n";
        str += whitespace(indent + 2) + fmt::format("'red' = {}\n", color->red());
        str += whitespace(indent + 2) + fmt::format("'green' = {}\n", color->green());
        str += whitespace(indent + 2) + fmt::format("'blue' = {}\n", color->blue());
        str += whitespace(indent + 2) + fmt::format("'alpha' = {}\n", color->alpha());
        str += whitespace(indent) + "]\n";

    } break;

    case rpg::Type::Table:
    {
        auto* table = any.as<rpg::Table>();

        str += "Table[\n";
        str += whitespace(indent + 2) + fmt::format("'totalSize' = {}\n", table->totalSize());
        str += whitespace(indent + 2) + fmt::format("'xSize' = {}\n", table->xSize());
        str += whitespace(indent + 2) + fmt::format("'ySize' = {}\n", table->ySize());
        str += whitespace(indent + 2) + fmt::format("'zSize' = {}\n", table->zSize());

        for (i32 i = 0; i < table->totalSize(); i++)
        {
            str += whitespace(indent + 2) + fmt::format("'{}' = ", i);
            str += fmt::format("{}", table->data().at(i));
            str += "\n";
        }

        str += whitespace(indent) + "]\n";

    } break;

    case rpg::Type::Tone:
    {
        auto* tone = any.as<rpg::Tone>();

        str += "Tone[\n";
        str += whitespace(indent + 2) + fmt::format("'red' = {}\n", tone->red());
        str += whitespace(indent + 2) + fmt::format("'green' = {}\n", tone->green());
        str += whitespace(indent + 2) + fmt::format("'blue' = {}\n", tone->blue());
        str += whitespace(indent + 2) + fmt::format("'grey' = {}\n", tone->grey());
        str += whitespace(indent) + "]\n";

    } break;

    default:
        throw std::runtime_error(fmt::format("Invalid type: {}", any.type()));
    }
}

void rxdataToJSON(const fs::path& inputDir, const fs::path& outputDir)
{
    fmt::print("Converting rxdata to json...\n\n");

    for (const auto& entry : fs::directory_iterator(inputDir))
    {
        if (entry.path().extension() == ".rxdata")
        {
            auto start = std::chrono::system_clock::now();

            auto bytes = loadFileIntoVector(entry.path().string());
            rpg::Reader reader{ bytes };

            auto any = reader.parse();
            auto type = entry.path().stem();
            json j;

            if (type == "Actors")
                ;
            else if (type == "Animations")
                ;
            else if (type == "Armors")
            {
                j = rpg::Armors{ *any.as<rpg::Array>() };
            }
            else if (type == "Classes")
                ;
            else if (type == "CommonEvents")
                ;
            else if (type == "Enemies")
                ;
            else if (type == "Items")
            {
                j = rpg::Items{ *any.as<rpg::Array>() };
            }
            else if (type == "MapInfos")
            {
                j = rpg::MapInfos{ *any.as<rpg::Hash>() };
            }
            else if (type.string().rfind("Map") == 0)
            {
                j = rpg::Map{ *any.as<rpg::Object>() };
            }
            else if (type == "Scripts")
                ;
            else if (type == "Skills")
                ;
            else if (type == "States")
            {
                j = rpg::States{ *any.as<rpg::Array>() };
            }
            else if (type == "System")
            {
                j = rpg::System{ *any.as<rpg::Object>() };
            }
            else if (type == "Tilesets")
                ;
            else if (type == "Troops")
                ;
            else if (type == "Weapons")
            {
                j = rpg::Weapons{ *any.as<rpg::Array>() };
            }

            fs::path outputPath = outputDir;
            outputPath /= entry.path().filename();
            outputPath.replace_extension("json");
            writeStringToFile(outputPath.string(), j.dump(4));

            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            fmt::print("'{}' took {}ms\n", entry.path().filename(), elapsed.count());
        }
    }

    fmt::print("\n");
}

void rxdataToTxt(const fs::path& inputDir, const fs::path& outputDir)
{
    fmt::print("Converting rxdata to txt...\n\n");

    for (const auto& entry : fs::directory_iterator(inputDir))
    {
        if (entry.path().extension() == ".rxdata")
        {
            auto start = std::chrono::system_clock::now();

            auto bytes = loadFileIntoVector(entry.path().string());
            rpg::Reader reader{ bytes };

            auto any = reader.parse();
            auto type = entry.path().stem();

            std::string output;
            writeToString(output, any);

            fs::path outputPath = outputDir;
            outputPath /= entry.path().filename();
            outputPath.replace_extension("txt");
            writeStringToFile(outputPath.string(), output);

            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            fmt::print("'{}' took {}ms\n", entry.path().filename(), elapsed.count());
        }
    }

    fmt::print("\n");
}
