#include "object.hpp"

Object::Object(std::string className)
: mClassName{ className }
, mVariables{}
{
}

Any& Object::operator[](const std::string& key)
{
	return mVariables[key];
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

bool Object::operator==(const Object & other) const
{
	return mVariables == other.mVariables;
}

bool Object::operator!=(const Object & other) const
{
	return !operator==(other);
}

bool Object::operator<(const Object & other) const
{
	return mVariables < other.mVariables;
}

size_t Object::size()
{
	return mVariables.size();
}

std::string Object::className()
{
	return mClassName;
}

std::map<std::string, Any> Object::variables()
{
	return mVariables;
}