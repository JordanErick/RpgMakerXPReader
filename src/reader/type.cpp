#include "reader/type.hpp"

std::string rpg::toString(const Type& type)
{
    switch (type)
    {
        case Type::Null:
            return "Null";
        case Type::Bool:
            return "Bool";
        case Type::Int:
            return "Int";
        case Type::String:
            return "String";
        case Type::Color:
            return "Color";
        case Type::Tone:
            return "Tone";
        case Type::Table:
            return "Table";
        case Type::Array:
            return "Array";
        case Type::Hash:
            return "Hash";
        case Type::Object:
            return "Object";
        default:
            throw std::runtime_error(fmt::format("Invalid enum value: {}", static_cast<i32>(type)));
    };
}
