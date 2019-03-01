#include "reader.hpp"

Reader::Reader(std::vector<u8> bytes)
: mIndex{0}
, mBytes{bytes}
, mSymbolCache{}
{
    readVersion();
}

Any Reader::parse()
{
    auto type = read<u8>();

    switch (type)
    {
        case '[': // Array
            return Any{ Type::Array, new Array{readArray()} };
        case 'l': // Bignum
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case 'F': // Bool
            return Any{ Type::Bool, new bool{false} };
        case 'T': // Bool
            return Any{ Type::Bool, new bool{true} };
        case 'c': // Class
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case 'd': // Data
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case 'e': // Extended
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case 'i': // Fixnum
            return Any{ Type::Fixnum, new int{readFixnum()} };
        case 'f': // Float
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case '{': // Hash
            return Any{ Type::Hash, new Hash(readHash()) };
        case '}': // HashDef
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case 'I': // Ivar
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case '@': // Link
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case 'm': // Module
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case 'M': // ModuleOld
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case '0': // Nil
            return Any{ Type::Nil, nullptr };
        case 'o': // Object
            return Any{ Type::Object, new Object(readObject()) };
        case '/': // Regexp
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case '"': // String
            return Any{ Type::String, new std::string{readString()} };
        case 'S': // Struct
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case ':': // Symbol
            return Any{ Type::Symbol, new std::string{readSymbol()} };
        case ';': // Symlink
            return Any{ Type::Symlink, new std::string{readSymlink()} };
        case 'C': // Uclass
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        case 'u': // UserDef
            return Any{ Type::UserDef, new Table(readUserDef()) };
        case 'U': // UserMarshal
            throw std::runtime_error(fmt::format("Not implemented: {}", type));
        default: // Unknown
            throw std::runtime_error(fmt::format("Unknown type: {}", type));
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

    if (className.type() != Type::Symbol && className.type() != Type::Symlink)
        throw std::runtime_error(fmt::format("Invalid class name type: {}", className.type()));

    Object object{ *className.as<std::string>() };

    auto variablesCount = readFixnum();

    for (i32 i = 0; i < variablesCount; i++)
    {
        auto key = parse();

        if(key.type() != Type::Symbol && key.type() != Type::Symlink)
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

Table Reader::readUserDef()
{
    auto name = parse();
    i32 size = readFixnum();

    Table table;
    
    table.dimensions = read<i32>();
    table.xLength = read<i32>();
    table.yLength = read<i32>();
    table.zLength = read<i32>();
    table.indices = read<i32>();
    table.data.reserve((size - 20) / 2);

    for (i32 i = 0; i < (size - 20) / 2; i++)
        table.data.push_back(read<i16>());

    return table;
}