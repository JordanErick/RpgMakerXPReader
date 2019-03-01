#include "any.hpp"

Any::Any()
: mType{Type::Unknown}
, mValue{nullptr}
{
}

Any::Any(Type type, void* value)
: mType{type}
, mValue{value}
{
}

Any::Any(const Any& other)
: mType{other.type()}
, mValue{nullptr}
{
    switch (mType.toValue())
    {
        case Type::Array:
            mValue = new Array{ *other.as<Array>() };
            break;

        case Type::Bignum:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Bool:
            mValue = new bool{ *other.as<bool>() };
            break;

        case Type::Class:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Data:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Extended:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Fixnum:
            mValue = new i32{ *other.as<i32>() };
            break;

        case Type::Float:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Hash:
            mValue = new Hash{ *other.as<Hash>() };
            break;

        case Type::HashDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Ivar:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Link:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Module:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::ModuleOld:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Nil:
            mValue = nullptr;
            break;

        case Type::Object:
            mValue = new Object{ *other.as<Object>() };
            break;

        case Type::Regexp:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::String:
            mValue = new std::string{ *other.as<std::string>() };
            break;

        case Type::Struct:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Symbol:
            mValue = new std::string{ *other.as<std::string>() };
            break;

        case Type::Symlink:
            mValue = new std::string{ *other.as<std::string>() };
            break;

        case Type::Uclass:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Unknown:
            throw std::runtime_error(fmt::format("Unknown type: {}", mType));
            break;

        case Type::UserDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::UserMarshal:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        default:
            throw std::runtime_error(fmt::format("Invalid type: {}", mType));
    }
}

Any& Any::operator=(const Any& other)
{
    destructor();
    mType = other.type();

    switch (mType.toValue())
    {
        case Type::Array:
            mValue = new Array{ *other.as<Array>() };
            break;

        case Type::Bignum:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Bool:
            mValue = new bool{ *other.as<bool>() };
            break;

        case Type::Class:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Data:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Extended:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Fixnum:
            mValue = new i32{ *other.as<i32>() };
            break;

        case Type::Float:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Hash:
            mValue = new Hash{ *other.as<Hash>() };
            break;

        case Type::HashDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Ivar:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Link:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Module:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::ModuleOld:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Nil:
            mValue = nullptr;
            break;

        case Type::Object:
            mValue = new Object{ *other.as<Object>() };
            break;

        case Type::Regexp:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::String:
            mValue = new std::string{ *other.as<std::string>() };
            break;

        case Type::Struct:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Symbol:
            mValue = new std::string{ *other.as<std::string>() };
            break;

        case Type::Symlink:
            mValue = new std::string{ *other.as<std::string>() };
            break;

        case Type::Uclass:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Unknown:
            throw std::runtime_error(fmt::format("Unknown type: {}", mType));
            break;

        case Type::UserDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::UserMarshal:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        default:
            throw std::runtime_error(fmt::format("Invalid type: {}", mType));
    }

    return *this;
}

Any::~Any()
{
    destructor();
}

bool Any::operator==(const Any& other) const
{
    if (mType != other.mType) return false;

    switch (mType.toValue())
    {
        case Type::Array:
            return *as<Array>() == *other.as<Array>();

        case Type::Bignum:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Bool:
            return *as<bool>() == *other.as<bool>();

        case Type::Class:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Data:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Extended:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Fixnum:
            return *as<i32>() == *other.as<i32>();

        case Type::Float:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Hash:
            return *as<Hash>() == *other.as<Hash>();

        case Type::HashDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Ivar:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Link:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Module:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::ModuleOld:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Nil:
            return true;

        case Type::Object:
            return *as<Object>() == *other.as<Object>();

        case Type::Regexp:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::String:
            return *as<std::string>() == *other.as<std::string>();

        case Type::Struct:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Symbol:
            return *as<std::string>() == *other.as<std::string>();

        case Type::Symlink:
            return *as<std::string>() == *other.as<std::string>();

        case Type::Uclass:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::Unknown:
            throw std::runtime_error(fmt::format("Unknown type: {}", mType));

        case Type::UserDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        case Type::UserMarshal:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));

        default:
            throw std::runtime_error(fmt::format("Invalid type: {}", mType));
    }
}

bool Any::operator!=(const Any& other) const
{
    return !operator==(other);
}

bool Any::operator<(const Any& other) const
{
    return mValue < other.mValue;
}

Type Any::type() const
{
    return mType;
}

void* Any::value() const
{
    return mValue;
}

void Any::destructor()
{
    switch (mType.toValue())
    {
        case Type::Array:
            delete as<Array>();
            break;

        case Type::Bignum:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Bool:
            delete as<bool>();
            break;

        case Type::Class:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Data:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Extended:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Fixnum:
            delete as<i32>();
            break;

        case Type::Float:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Hash:
            delete as<Hash>();
            break;

        case Type::HashDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Ivar:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Link:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Module:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::ModuleOld:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Nil:
            break;

        case Type::Object:
            delete as<Object>();
            break;

        case Type::Regexp:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::String:
            delete as<std::string>();
            break;

        case Type::Struct:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Symbol:
            delete as<std::string>();
            break;

        case Type::Symlink:
            delete as<std::string>();
            break;

        case Type::Uclass:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::Unknown:
            break;

        case Type::UserDef:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        case Type::UserMarshal:
            throw std::runtime_error(fmt::format("Not implemented: {}", mType));
            break;

        default:
            throw std::runtime_error(fmt::format("Invalid type: {}", mType));
    }

    mValue = nullptr;
}

Object::Object(std::string className)
: mClassName{className}
, mVariables{}
{
}

Any& Object::operator[](const std::string& key)
{
    return mVariables[key];
}

std::map<std::string, Any>::iterator Object::begin()
{
    return mVariables.begin();
}

std::map<std::string, Any>::const_iterator Object::begin() const
{
    return mVariables.begin();
}

std::map<std::string, Any>::iterator Object::end()
{
    return mVariables.end();
}

std::map<std::string, Any>::const_iterator Object::end() const
{
    return mVariables.end();
}

bool Object::operator==(const Object & other) const
{
    return mVariables == other.mVariables;
}

bool Object::operator!=(const Object & other) const
{
    return !operator==(other);
}

bool Object::operator<(const Object & other) const
{
    return mVariables < other.mVariables;
}

size_t Object::size()
{
    return mVariables.size();
}

std::string Object::className()
{
    return mClassName;
}

std::map<std::string, Any> Object::variables()
{
    return mVariables;
}