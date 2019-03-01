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

class Object
{
public:
    Object(std::string className);

    Any& operator[](const std::string& key);

    std::map<std::string, Any>::iterator begin();
    std::map<std::string, Any>::const_iterator begin() const;

    std::map<std::string, Any>::iterator end();
    std::map<std::string, Any>::const_iterator end() const;

    bool operator==(const Object& other) const;
    bool operator!=(const Object& other) const;
    bool operator<(const Object& other) const;

    size_t size();

    std::string className();
    std::map<std::string, Any> variables();

private:
    std::string mClassName;
    std::map<std::string, Any> mVariables;
};
