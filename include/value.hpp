#pragma once

#include "utility.hpp"

class Value
{
public:
    enum class Type
    {
        Nil,
        Bool,
        Fixnum,
        Float,
        String,
        Symbol,
        Symlink,
        Array,
        Hash,
        Object,
        UserDef,

        Bignum,
        Class,
        Data,
        Extended,
        Ivar,
        Link,
        ModuleOld,
        Module,
        Regexp,
        Struct,
        UsrMarshal,

        Unknown,
    };

    Value();
    Value(Type type, void* value);
    Value(const Value& other);
    Value& operator=(const Value&);
    ~Value();

    Type getType() const { return mType; }
    void* getValue() const { return mValue; }

    friend bool operator<(const Value& a, const Value& b);

private:
    Type mType;
    void* mValue;
};

bool operator<(const Value& a, const Value& b);
std::ostream& operator<<(std::ostream& stream, Value::Type type);
std::string toString(Value::Type type);