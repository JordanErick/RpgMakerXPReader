#pragma once

#include "utility.hpp"
#include "type.hpp"

class Any
{
public:
    Any();
    Any(Type type, void* value);
    Any(const Any& other);
    Any& operator=(const Any& other);
    ~Any();

    bool operator==(const Any& other) const;
    bool operator!=(const Any& other) const;
    bool operator<(const Any& other) const;

    Type type() const;
    void* value() const;

    template<typename T>
    T* as() const { return static_cast<T*>(mValue); }

private:
    void destructor();

private:
    Type mType;
    void* mValue;
};

using Array = std::vector<Any>;
using Hash = std::map<Any, Any>;

struct Table
{
    i32 dimensions;
    i32 xSize;
    i32 ySize;
    i32 zSize;
    i32 totalSize;
    std::vector<i16> data;

    bool operator==(const Table& other) const;
    bool operator!=(const Table& other) const;
    bool operator<(const Table& other) const;
};

struct Tone
{
    double red;
    double green;
    double blue;
    double grey;

    bool operator==(const Tone& other) const;
    bool operator!=(const Tone& other) const;
    bool operator<(const Tone& other) const;
};

struct Color
{
    double red;
    double green;
    double blue;
    double alpha;

    bool operator==(const Color& other) const;
    bool operator!=(const Color& other) const;
    bool operator<(const Color& other) const;
};