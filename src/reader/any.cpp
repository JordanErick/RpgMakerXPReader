#include "reader/any.hpp"
#include "reader/object.hpp"

Any::Any()
: mType{Type::Null}
, mValue{nullptr}
{
}

Any::Any(Type type, void* value)
: mType{type}
, mValue{value}
{
}

Any::Any(const Any& other)
: mType{other.mType}
, mValue{nullptr}
{
    switch (other.mType)
    {
        case Type::Null:
            break;
        case Type::Bool:
            mValue = new bool{ *other.as<bool>() };
            break;
        case Type::Int:
            mValue = new i32{ *other.as<i32>() };
            break;
        case Type::String:
            mValue = new std::string{ *other.as<std::string>() };
            break;
        case Type::Color:
            mValue = new Color{ *other.as<Color>() };
            break;
        case Type::Tone:
            mValue = new Tone{ *other.as<Tone>() };
            break;
        case Type::Table:
            mValue = new Table{ *other.as<Table>() };
            break;
        case Type::Array:
            mValue = new Array{ *other.as<Array>() };
            break;
        case Type::Hash:
            mValue = new Hash{ *other.as<Hash>() };
            break;
        case Type::Object:
            mValue = new Object{ *other.as<Object>() };
            break;
        default:
            throw std::runtime_error(fmt::format("Unsupported enum value: {}", static_cast<i32>(other.mType)));
    };
}

Any& Any::operator=(const Any& other)
{
    destructor();

    mType = other.mType;
    mValue = nullptr;

    switch (other.mType)
    {
        case Type::Null:
            break;
        case Type::Bool:
            mValue = new bool{ *other.as<bool>() };
            break;
        case Type::Int:
            mValue = new i32{ *other.as<i32>() };
            break;
        case Type::String:
            mValue = new std::string{ *other.as<std::string>() };
            break;
        case Type::Color:
            mValue = new Color{ *other.as<Color>() };
            break;
        case Type::Tone:
            mValue = new Tone{ *other.as<Tone>() };
            break;
        case Type::Table:
            mValue = new Table{ *other.as<Table>() };
            break;
        case Type::Array:
            mValue = new Array{ *other.as<Array>() };
            break;
        case Type::Hash:
            mValue = new Hash{ *other.as<Hash>() };
            break;
        case Type::Object:
            mValue = new Object{ *other.as<Object>() };
            break;
        default:
            throw std::runtime_error(fmt::format("Unsupported enum value: {}", static_cast<i32>(other.mType)));
    };

    return *this;
}

Any::~Any()
{
    destructor();
}

bool Any::operator==(const Any& other) const
{
    if (mType != other.mType) return false;

    switch (other.mType)
    {
        case Type::Null:
            return true;
        case Type::Bool:
            return *as<bool>() == *other.as<bool>();
        case Type::Int:
            return *as<i32>() == *other.as<i32>();
        case Type::String:
            return *as<std::string>() == *other.as<std::string>();
        case Type::Color:
            return *as<Color>() == *other.as<Color>();
        case Type::Tone:
            return *as<Tone>() == *other.as<Tone>();
        case Type::Table:
            return *as<Table>() == *other.as<Table>();
        case Type::Array:
            return *as<Array>() == *other.as<Array>();
        case Type::Hash:
            return *as<Hash>() == *other.as<Hash>();
        case Type::Object:
            return *as<Object>() == *other.as<Object>();
        default:
            throw std::runtime_error(fmt::format("Unsupported enum value: {}", static_cast<i32>(other.mType)));
    };
}

bool Any::operator!=(const Any& other) const
{
    return !operator==(other);
}

bool Any::operator<(const Any& other) const
{
    if (mType != other.mType)
        return mType < other.mType;

    switch (other.mType)
    {
        case Type::Null:
            return true;
        case Type::Bool:
            return *as<bool>() < *other.as<bool>();
        case Type::Int:
            return *as<i32>() < *other.as<i32>();
        case Type::String:
            return *as<std::string>() < *other.as<std::string>();
        case Type::Color:
            return *as<Color>() < *other.as<Color>();
        case Type::Tone:
            return *as<Tone>() < *other.as<Tone>();
        case Type::Table:
            return *as<Table>() < *other.as<Table>();
        case Type::Array:
            return *as<Array>() < *other.as<Array>();
        case Type::Hash:
            return *as<Hash>() < *other.as<Hash>();
        case Type::Object:
            return *as<Object>() < *other.as<Object>();
        default:
            throw std::runtime_error(fmt::format("Unsupported enum value: {}", static_cast<i32>(other.mType)));
    };
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
    switch (mType)
    {
        case Type::Null:
            break;
        case Type::Bool:
            delete as<bool>();
            break;
        case Type::Int:
            delete as<i32>();
            break;
        case Type::String:
            delete as<std::string>();
            break;
        case Type::Color:
            delete as<Color>();
            break;
        case Type::Tone:
            delete as<Tone>();
            break;
        case Type::Table:
            delete as<Table>();
            break;
        case Type::Array:
            delete as<Array>();
            break;
        case Type::Hash:
            delete as<Hash>();
            break;
        case Type::Object:
            delete as<Object>();
            break;
        default:
            throw std::runtime_error(fmt::format("Unsupported enum value: {}", static_cast<i32>(mType)));
    };
}
