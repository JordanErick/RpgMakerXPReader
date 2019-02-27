#include "value.hpp"

Value::Value()
: mType{ Type::Unknown }
, mValue{ nullptr }
{
}

Value::Value(Type type, void* value)
: mType{ type }
, mValue{ value }
{
}

Value::Value(const Value& other)
: mType{ other.mType }
, mValue{ nullptr }
{
    switch (mType)
    {
        case Type::Nil:
            // Do nothing
            break;
        case Type::Bool:
            mValue = new bool{ *(static_cast<bool*>(other.getValue())) };
            break;
        case Type::Fixnum:
            mValue = new int{ *(static_cast<int*>(other.getValue())) };
            break;
        case Type::Float:
            // NYI
            break;
        case Type::String:
            mValue = new std::string{ *(static_cast<std::string*>(other.getValue())) };
            break;
        case Type::Symbol:
            mValue = new std::string{ *(static_cast<std::string*>(other.getValue())) };
            break;
        case Type::Symlink:
            mValue = new std::string{ *(static_cast<std::string*>(other.getValue())) };
            break;
        case Type::Array:
            mValue = new std::vector<Value>{ *(static_cast<std::vector<Value>*>(other.getValue())) };
            break;
        case Type::Hash:
            mValue = new std::map<Value, Value>{ *(static_cast<std::map<Value, Value>*>(other.getValue())) };
            break;
        case Type::Object:
            mValue = new std::map<Value, Value>{ *(static_cast<std::map<Value, Value>*>(other.getValue())) };
            break;
        case Type::UserDef:
            mValue = new Table{ *(static_cast<Table*>(other.getValue())) };
        case Type::Unknown:
            // Do nothing
            break;
        default:
            break;
    }
}

Value& Value::operator=(const Value& other)
{
    mType = other.mType;
    mValue = nullptr;

    switch (mType)
    {
        case Type::Nil:
            // Do nothing
            break;
        case Type::Bool:
            mValue = new bool{ *(static_cast<bool*>(other.getValue())) };
            break;
        case Type::Fixnum:
            mValue = new int{ *(static_cast<int*>(other.getValue())) };
            break;
        case Type::Float:
            // NYI
            break;
        case Type::String:
            mValue = new std::string{ *(static_cast<std::string*>(other.getValue())) };
            break;
        case Type::Symbol:
            mValue = new std::string{ *(static_cast<std::string*>(other.getValue())) };
            break;
        case Type::Symlink:
            mValue = new std::string{ *(static_cast<std::string*>(other.getValue())) };
            break;
        case Type::Array:
            mValue = new std::vector<Value>{ *(static_cast<std::vector<Value>*>(other.getValue())) };
            break;
        case Type::Hash:
            mValue = new std::map<Value, Value>{ *(static_cast<std::map<Value, Value>*>(other.getValue())) };
            break;
        case Type::Object:
            mValue = new std::map<Value, Value>{ *(static_cast<std::map<Value, Value>*>(other.getValue())) };
            break;
        case Type::UserDef:
            mValue = new Table{ *(static_cast<Table*>(other.getValue())) };
        case Type::Unknown:
            // Do nothing
            break;
        default:
            break;
    }

    return *this;
}

Value::~Value()
{
    switch (mType)
    {
        case Type::Nil:
            // Do nothing
            break;
        case Type::Bool:
            delete static_cast<bool*>(mValue);
            break;
        case Type::Fixnum:
            delete static_cast<int*>(mValue);
            break;
        case Type::Float:
            // NYI
            break;
        case Type::String:
            delete static_cast<std::string*>(mValue);
            break;
        case Type::Symbol:
            delete static_cast<std::string*>(mValue);
            break;
        case Type::Symlink:
            delete static_cast<std::string*>(mValue);
            break;
        case Type::Array:
            delete static_cast<std::vector<Value>*>(mValue);
            break;
        case Type::Hash:
            delete static_cast<std::map<Value, Value>*>(mValue);
            break;
        case Type::Object:
            delete static_cast<std::map<Value, Value>*>(mValue);
            break;
        case Type::UserDef:
            delete static_cast<Table*>(mValue);
        case Type::Unknown:
            // Do nothing
            break;
        default:
            break;
    }
}

bool operator<(const Value & a, const Value & b)
{
    return a.mValue < b.mValue;
}

std::ostream & operator<<(std::ostream & stream, Value::Type type)
{
    return stream << toString(type);
}

std::string toString(Value::Type type)
{
    switch (type)
    {
        case Value::Type::Nil:
            return "Nil";
        case Value::Type::Bool:
            return "Bool";
        case Value::Type::Fixnum:
            return "Fixnum";
        case Value::Type::Float:
            return "Float";
        case Value::Type::String:
            return "String";
        case Value::Type::Symbol:
            return "Symbol";
        case Value::Type::Symlink:
            return "Symlink";
        case Value::Type::Array:
            return "Array";
        case Value::Type::Hash:
            return "Hash";
        case Value::Type::Object:
            return "Object";
        case Value::Type::UserDef:
            return "UserDef";
        case Value::Type::Unknown:
            return "Unknown";
        default:
            return "NYI";
    }
}
