#pragma once

#include "utility.hpp"

enum class Type : i32
{
    Null,
    Bool,
    Int,
    String,
    Color,
    Tone,
    Table,
    Array,
    Hash,
    Object,
};

std::string toString(const Type& type);

template<>
struct fmt::formatter<Type>
{
    template<typename ParseContext>
    constexpr auto parse(ParseContext& ctx) { return ctx.begin(); }

    template<typename FormatContext>
    auto format(const Type& type, FormatContext& ctx)
    {
        return format_to(ctx.out(), toString(type));
    }
};