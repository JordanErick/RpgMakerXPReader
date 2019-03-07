#include "type.hpp"

std::string toString(const Type& type)
{
    switch (type)
    {
        case Type::Array: 
            return "Array";
        case Type::Bignum:
            return "Bignum";
        case Type::Bool:
            return "Bool";
        case Type::Class:
            return "Class";
        case Type::Data:
            return "Data";
        case Type::Extended:
            return "Extended";
        case Type::Fixnum:
            return "Fixnum";
        case Type::Float:
            return "Float";
        case Type::Hash:
            return "Hash";
        case Type::HashDef:
            return "HashDef";
        case Type::Ivar:
            return "Ivar";
        case Type::Link:
            return "Link";
        case Type::Module:
            return "Module";
        case Type::ModuleOld:
            return "ModuleOld";
        case Type::Nil:
            return "Nil";
        case Type::Object:
            return "Object";
        case Type::Regexp:
            return "Regexp";
        case Type::String:
            return "String";
        case Type::Struct:
            return "Struct";
        case Type::Symbol:
            return "Symbol";
        case Type::Symlink:
            return "Symlink";
        case Type::Uclass:
            return "Uclass";
        case Type::Unknown:
            return "Unknown";
        case Type::UserDef:
            return "UserDef";
        case Type::UserMarshal:
            return "UserMarshal";
        case Type::Color:
            return "Color";
        case Type::Table:
            return "Table";
        case Type::Tone:
            return "Tone";
        default:
            throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<i32>(type)));
    }
}
