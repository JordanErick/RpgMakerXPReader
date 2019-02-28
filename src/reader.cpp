#include "reader.hpp"

MarshalReader::MarshalReader(std::vector<u8> bytes)
: mBytes{bytes}
, mIndex{0}
, mSymbolCache{}
{
    if (read<u8>() != 4 || read<u8>() != 8)
        throw std::runtime_error("invalid marshal version");
}

Value MarshalReader::parse()
{
    auto type = read<u8>();

    switch (type)
    {
        case '0': // TYPE_NIL
            return Value{ Value::Type::Nil, nullptr };
        case 'T': // TYPE_TRUE
            return Value{ Value::Type::Bool, new bool{true} };
        case 'F': // TYPE_FALSE
            return Value{ Value::Type::Bool, new bool{false} };
        case 'i': // TYPE_FIXNUM
            return Value{ Value::Type::Fixnum, new int{readFixnum()} };
        case 'f': // TYPE_FLOAT
            return Value{ Value::Type::Float, nullptr };
        case '"': // TYPE_STRING
            return Value{ Value::Type::String, new std::string{readString()} };
        case ':': // TYPE_SYMBOL
            return Value{ Value::Type::Symbol, new std::string{readSymbol()} };
        case ';': // TYPE_SYMLINK
            return Value{ Value::Type::Symlink, new std::string{readSymlink()} };
        case '[': // TYPE_ARRAY
            return Value{ Value::Type::Array, new std::vector<Value>{readArray()} };
        case '{': // TYPE_HASH
            return Value{ Value::Type::Hash, new std::map<Value, Value>(readHash()) };
        case 'o': // TYPE_OBJECT
            return Value{ Value::Type::Object, new std::map<Value, Value>(readObject()) };

        case 'l': // TYPE_BIGNUM
            return Value{ Value::Type::Bignum, nullptr };
        case 'c': // TYPE_CLASS
            return Value{ Value::Type::Class, nullptr };
        case 'd': // TYPE_DATA
            return Value{ Value::Type::Data, nullptr };
        case 'e': // TYPE_EXTENDED
            return Value{ Value::Type::Extended, nullptr };
        case 'I': // TYPE_IVAR
            return Value{ Value::Type::Ivar, nullptr };
        case '@': // TYPE_LINK
            return Value{ Value::Type::Link, nullptr };
        case 'M': // TYPE_MODULE_OLD
            return Value{ Value::Type::ModuleOld, nullptr };
        case 'm': // TYPE_MODULE
            return Value{ Value::Type::Module, nullptr };
        case '/': // TYPE_REGEXP
            return Value{ Value::Type::Regexp, nullptr };
        case 'S': // TYPE_STRUCT
            return Value{ Value::Type::Struct, nullptr };
        case 'u': // TYPE_USERDEF
            return Value{ Value::Type::UserDef, new Table(readUserDef()) };
        case 'U': // TYPE_USRMARSHAL
            return Value{ Value::Type::UsrMarshal, nullptr };
    }

    return Value{};
}

int MarshalReader::readFixnum()
{
    i8 byte = read<i8>();

    if (byte == 0) return 0;

    if (byte > 0)
    {
        if (4 < byte && byte < 128) return byte - 5;

        if (byte > static_cast<i8>(sizeof(int)))
            throw std::runtime_error("too big int");

        int value = 0;
        for (int i = 0; i < byte; i++)
            value |= static_cast<int>(read<u8>()) << (8 * i);

        return value;
    }
    else
    {
        if (-129 < byte && byte < -4) return byte + 5;

        byte = -byte;

        if (byte > static_cast<i8>(sizeof(int)))
            throw std::runtime_error("too big int");

        int value = -1;
        for (int i = 0; i < byte; i++)
        {
            value &= ~(static_cast<int>(0xff) << (8 * i));
            value |= static_cast<int>(read<u8>()) << (8 * i);
        }

        return value;
    }
}

std::string MarshalReader::readString()
{
    int length = readFixnum();

    std::string value;
    value.reserve(length);

    for (int i = 0; i < length; i++)
        value += read<i8>();

    return value;
}

std::string MarshalReader::readSymbol()
{
    int length = readFixnum();

    std::string value;
    value.reserve(length);

    for (int i = 0; i < length; i++)
        value += read<i8>();

    if (std::find(mSymbolCache.begin(), mSymbolCache.end(), value) == mSymbolCache.end())
        mSymbolCache.push_back(value);

    return value;
}

std::vector<Value> MarshalReader::readArray()
{
    int length = readFixnum();

    std::vector<Value> values;
    values.reserve(length);

    for (int i = 0; i < length; i++)
        values.push_back(parse());

    return values;
}

std::map<Value, Value> MarshalReader::readObject()
{
    auto className = parse();

    if (className.getType() != Value::Type::Symbol && className.getType() != Value::Type::Symlink)
        throw std::runtime_error("invalid class name type");

    auto ivarCount = readFixnum();

    std::map<Value, Value> object;

    for (int i = 0; i < ivarCount; i++)
    {
        auto key = parse();
        auto value = parse();
        object[key] = value;
    }

    return object;
}

std::map<Value, Value> MarshalReader::readHash()
{
    std::map<Value, Value> hash;

    auto entriesCount = readFixnum();

    for (int i = 0; i < entriesCount; i++)
    {
        auto key = parse();
        auto value = parse();
        hash[key] = value;
    }

    return hash;

    return std::map<Value, Value>();
}

std::string MarshalReader::readSymlink()
{
    auto cacheIndex = readFixnum();
    return mSymbolCache[cacheIndex];
}

Table MarshalReader::readUserDef()
{
    auto name = parse();
    auto size = readFixnum();

    Table table;
    
    table.dimensions = read<i32>();
    table.xLength = read<i32>();
    table.yLength = read<i32>();
    table.zLength = read<i32>();
    table.indices = read<i32>();
    table.data.reserve((size - 20) / 2);

    for (int i = 0; i < (size - 20) / 2; i++)
        table.data.push_back(read<i16>());

    return table;
}
