#include "reader/object.hpp"

rpg::Object::Object(const std::string& className)
: mClassName{ className }
, mVariables{}
{
}

rpg::Any& rpg::Object::operator[](const std::string& key)
{
    return mVariables[key];
}

const rpg::Any& rpg::Object::operator[](const std::string& key) const
{
    return mVariables.at(key);
}

std::map<std::string, rpg::Any>::iterator rpg::Object::begin()
{
    return mVariables.begin();
}

std::map<std::string, rpg::Any>::const_iterator rpg::Object::begin() const
{
    return mVariables.begin();
}

std::map<std::string, rpg::Any>::iterator rpg::Object::end()
{
    return mVariables.end();
}

std::map<std::string, rpg::Any>::const_iterator rpg::Object::end() const
{
    return mVariables.end();
}

bool rpg::Object::operator==(const Object& other) const
{
    return mVariables == other.mVariables;
}

bool rpg::Object::operator!=(const Object& other) const
{
    return !operator==(other);
}

bool rpg::Object::operator<(const Object& other) const
{
    return mVariables < other.mVariables;
}

size_t rpg::Object::size() const
{
    return mVariables.size();
}

const std::string& rpg::Object::className() const
{
    return mClassName;
}