#include "reader.hpp"

Reader::Reader(const std::vector<u8>& bytes)
: mIndex{0}
, mBytes{bytes}
, mSymbolCache{}
, mObjectCache{}
{
    readVersion();
}

Any Reader::parse()
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

void Reader::readVersion()
{
    auto major = read<u8>();
    auto minor = read<u8>();

    if (major != 4 || minor != 8)
        throw std::runtime_error(fmt::format("Invalid marshal version: {}.{]", major, minor));
}

Any Reader::readFixnum()
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

Any Reader::readString()
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

Any Reader::readSymbol()
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

Any Reader::readSymlink()
{
    i32 cacheIndex = *readFixnum().as<i32>();
    return { Type::String, new std::string{mSymbolCache[cacheIndex]} };
}

Any Reader::readUserDef()
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

Any Reader::readArray()
{
    i32 length = *readFixnum().as<i32>();

    auto* array = new Array{};

    for (i32 i = 0; i < length; i++)
        array->push_back(parse());

    auto any = Any{ Type::Array, array };
    mObjectCache.push_back(any);

    return any;
}

Any Reader::readHash()
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

Any Reader::readObject()
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

Any Reader::readLink()
{
    // TODO: Implement this and make sure we have valid object cache
    i32 cacheIndex = *readFixnum().as<i32>();
    auto* tmp = new std::string{ fmt::format("LINK_{}_{}", cacheIndex, mObjectCache[cacheIndex].type()) };
    return Any{ Type::String, tmp };
}
