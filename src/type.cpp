#include "type.hpp"

Type::Type(Type::Value value)
: mValue{ value }
{
}

bool Type::operator==(Type other) const
{
    return mValue == other.mValue;
}

bool Type::operator!=(Type other) const
{
    return mValue != other.mValue;
}

bool Type::operator<(Type other) const
{
    return mValue < other.mValue;
}

std::string Type::toString() const
{
    switch (mValue)
    {
        case Array:
            return "Array";
        case Bignum:
            return "Bignum";
        case Bool:
            return "Bool";
        case Class:
            return "Class";
        case Data:
            return "Data";
        case Extended:
            return "Extended";
        case Fixnum:
            return "Fixnum";
        case Float:
            return "Float";
        case Hash:
            return "Hash";
        case HashDef:
            return "HashDef";
        case Ivar:
            return "Ivar";
        case Link:
            return "Link";
        case Module:
            return "Module";
        case ModuleOld:
            return "ModuleOld";
        case Nil:
            return "Nil";
        case Object:
            return "Object";
        case Regexp:
            return "Regexp";
        case String:
            return "String";
        case Struct:
            return "Struct";
        case Symbol:
            return "Symbol";
        case Symlink:
            return "Symlink";
        case Uclass:
            return "Uclass";
        case Unknown:
            return "Unknown";
        case UserDef:
            return "UserDef";
        case UserMarshal:
            return "UserMarshal";
        case Table:
            return "Table";
        case Tone:
            return "Tone";
        default:
            throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<i32>(mValue)));
    }
}

i32 Type::toValue() const
{
    return static_cast<i32>(mValue);
}