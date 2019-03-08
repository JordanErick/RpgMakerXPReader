#pragma once

#include "any.hpp"

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