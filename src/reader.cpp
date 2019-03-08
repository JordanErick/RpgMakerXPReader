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
			return Any{ Type::Int, new int{readFixnum()} };
		case '"': // String
		{
			auto any = Any{ Type::String, new std::string{readString()} };
			mObjectCache.push_back(any);
			return any;
		}
		case ':': // Symbol
			return Any{ Type::String, new std::string{readSymbol()} };
		case ';': // Symlink
		{
			auto any = Any{ Type::String, new std::string{readSymlink()} };
			mObjectCache.push_back(any);
			return any;
		}	
		case 'u': // UserDef
		{
			auto any = readUserDef();
			mObjectCache.push_back(any);
			return any;
		}
		case '[': // Array
		{
			auto any = Any{ Type::Array, new Array{readArray()} };
			mObjectCache.push_back(any);
			return any;
		}
		case '{': // Hash
		{
			auto any = Any{ Type::Hash, new Hash(readHash()) };
			mObjectCache.push_back(any);
			return any;
		}
		case 'o': // Object
		{
			auto any = Any{ Type::Object, new Object(readObject()) };
			mObjectCache.push_back(any);
			return any;
		}
		case '@': // Link
		{
			auto any = Any{ Type::String, new std::string{readLink()} };
			mObjectCache.push_back(any);
			return any;
		}
		default:
			throw std::runtime_error(fmt::format("Unsupported type specifier: {}", type));
	}
}

i32 Reader::readFixnum()
{
    auto byte = read<i8>();

    if (byte == 0) return 0;

    if (byte > 0)
    {
        if (4 < byte && byte < 128) return byte - 5;

        if (byte > static_cast<i8>(sizeof(i32)))
            throw std::runtime_error("Too big int");

        i32 value = 0;
        for (i32 i = 0; i < byte; i++)
            value |= static_cast<i32>(read<u8>()) << (8 * i);

        return value;
    }
    else
    {
        if (-129 < byte && byte < -4) return byte + 5;

        byte = -byte;

        if (byte > static_cast<i8>(sizeof(i32)))
            throw std::runtime_error("too big int");

        i32 value = -1;
        for (i32 i = 0; i < byte; i++)
        {
            value &= ~(static_cast<i32>(0xff) << (8 * i));
            value |= static_cast<i32>(read<u8>()) << (8 * i);
        }

        return value;
    }
}

std::string Reader::readString()
{
    i32 length = readFixnum();

    std::string value;
    value.reserve(length);

    for (i32 i = 0; i < length; i++)
        value += read<i8>();

    return value;
}

std::string Reader::readSymbol()
{
    i32 length = readFixnum();

    std::string value;
    value.reserve(length);

    for (i32 i = 0; i < length; i++)
        value += read<i8>();

    if (std::find(mSymbolCache.begin(), mSymbolCache.end(), value) == mSymbolCache.end())
        mSymbolCache.push_back(value);

    return value;
}

void Reader::readVersion()
{
    auto major = read<u8>();
    auto minor = read<u8>();

    if (major != 4 || minor != 8)
        throw std::runtime_error(fmt::format("Invalid marshal version: {}.{]", major, minor));
}

Array Reader::readArray()
{
    i32 length = readFixnum();

    Array array;

    for (i32 i = 0; i < length; i++)
        array.push_back(parse());

    return array;
}

Object Reader::readObject()
{
    auto className = parse();

    if (className.type() != Type::String)
        throw std::runtime_error(fmt::format("Invalid class name type: {}", className.type()));

    Object object{ *className.as<std::string>() };

    auto variablesCount = readFixnum();

    for (i32 i = 0; i < variablesCount; i++)
    {
        auto key = parse();

        if(key.type() != Type::String)
            throw std::runtime_error(fmt::format("Invalid key type: {}", key.type()));

        auto value = parse();
        object[*key.as<std::string>()] = value;
    }

    return object;
}

Hash Reader::readHash()
{
    Hash hash;

    i32 entriesCount = readFixnum();

    for (i32 i = 0; i < entriesCount; i++)
    {
        auto key = parse();
        auto value = parse();
        hash[key] = value;
    }

    return hash;
}

std::string Reader::readSymlink()
{
    i32 cacheIndex = readFixnum();
    return mSymbolCache[cacheIndex];
}

Any Reader::readUserDef()
{
    auto name = parse();

    if (name.type() != Type::String)
        throw std::runtime_error(fmt::format("Invalid name type: {}", name.type()));

    i32 size = readFixnum();

    if (*name.as<std::string>() == "Color")
    {
        auto red = read<double>();
        auto green = read<double>();
        auto blue = read<double>();
        auto alpha = read<double>();

        return Any{ Type::Color, new Color{red, green, blue, alpha} };
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

        return Any{ Type::Table, new Table{dimensions, xSize, ySize, zSize, totalSize, std::move(data)} };
    }
    else if (*name.as<std::string>() == "Tone")
    {
        auto red = read<double>();
        auto green = read<double>();
        auto blue = read<double>();
        auto grey = read<double>();

        return Any{ Type::Tone, new Tone{red, green, blue, grey} };
    }
    else
        throw std::runtime_error(fmt::format("Unsupported user defined class: {}", *name.as<std::string>()));
}

std::string Reader::readLink()
{
    // TODO: Fix me
    i32 cacheIndex = readFixnum();
    return fmt::format("LINK_{}_{}", cacheIndex, mObjectCache[cacheIndex].type());
}
