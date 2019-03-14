#include "reader/object.hpp"

Object::Object(const std::string& className)
: mClassName{ className }
, mVariables{}
{
}

Any& Object::operator[](const std::string& key)
{
    return mVariables[key];
}

const Any& Object::operator[](const std::string& key) const
{
    return mVariables.at(key);
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

bool Object::operator==(const Object& other) const
{
    return mVariables == other.mVariables;
}

bool Object::operator!=(const Object& other) const
{
    return !operator==(other);
}

bool Object::operator<(const Object& other) const
{
    return mVariables < other.mVariables;
}

size_t Object::size() const
{
    return mVariables.size();
}

const std::string& Object::className() const
{
    return mClassName;
}