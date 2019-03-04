#pragma once

#include "utility.hpp"

class Type
{
public:
    enum Value : i32
    {
        Array,       // [
        Bignum,      // l
        Bool,        // F T
        Class,       // c
        Data,        // d
        Extended,    // e
        Fixnum,      // i
        Float,       // f
        Hash,        // { 
        HashDef,     // }
        Ivar,        // I
        Link,        // @
        Module,      // m
        ModuleOld,   // M
        Nil,         // 0
        Object,      // o
        Regexp,      // /
        String,      // "
        Struct,      // S
        Symbol,      // :
        Symlink,     // ;
        Uclass,      // C
        Unknown,     // 
        UserDef,     // u
        UserMarshal, // U

        // User defined classes from RPG Maker XP
        Table,
        Tone,
    };

    Type() = default;
    Type(Type::Value value);

    bool operator==(Type other) const;
    bool operator!=(Type other) const;
    bool operator<(Type other) const;

    std::string toString() const;
    i32 toValue() const;
private:
    Type::Value mValue;
};

template<>
struct fmt::formatter<Type>
{
    template<typename ParseContext>
    constexpr auto parse(ParseContext& ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const Type& type, FormatContext& ctx)
    {
        return format_to(ctx.out(), type.toString());
    }
};