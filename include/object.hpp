#pragma once

#include "any.hpp"

class Object
{
public:
                                               Object(const std::string& className);

    Any&                                       operator[](const std::string& key);
    const Any&                                 operator[](const std::string& key) const;

    std::map<std::string, Any>::iterator       begin();
    std::map<std::string, Any>::const_iterator begin() const;

    std::map<std::string, Any>::iterator       end();
    std::map<std::string, Any>::const_iterator end() const;

    bool                                       operator==(const Object& other) const;
    bool                                       operator!=(const Object& other) const;
    bool                                       operator<(const Object& other) const;

    size_t                                     size() const;
    const std::string&                         className() const;
private:
    std::string                                mClassName;
    std::map<std::string, Any>                 mVariables;
};