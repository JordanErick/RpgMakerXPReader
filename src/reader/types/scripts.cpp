#include "reader/types/scripts.hpp"

rpg::Scripts::Scripts()
: mScripts{}
{
}

rpg::Scripts::Scripts(const Array& array)
: mScripts{}
{
    for (size_t i = 0; i < array.size(); i++)
    {
        auto& element = array[i];

        if (element.type() != Type::Array)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Array>()->size() != 3)
            throw std::runtime_error(fmt::format("Invalid array size: {}", element.as<Array>()->size()));

        mScripts.push_back(Script{ *element.as<Array>() });
    }
}

rpg::Script& rpg::Scripts::operator[](size_t index)
{
    return mScripts[index];
}

const rpg::Script& rpg::Scripts::operator[](size_t index) const
{
    return mScripts.at(index);
}

std::vector<rpg::Script>::iterator rpg::Scripts::begin()
{
    return mScripts.begin();
}

std::vector<rpg::Script>::const_iterator rpg::Scripts::begin() const
{
    return mScripts.begin();
}

std::vector<rpg::Script>::iterator rpg::Scripts::end()
{
    return mScripts.end();
}

std::vector<rpg::Script>::const_iterator rpg::Scripts::end() const
{
    return mScripts.end();
}

bool rpg::Scripts::operator==(const Scripts& other) const
{
    return mScripts == other.mScripts;
}

bool rpg::Scripts::operator!=(const Scripts& other) const
{
    return !operator==(other);
}

bool rpg::Scripts::operator<(const Scripts& other) const
{
    return mScripts < other.mScripts;
}

size_t rpg::Scripts::size() const
{
    return mScripts.size();
}

void rpg::to_json(json& j, const Scripts& o)
{
    j = json{ JSON_SET(Scripts) };
}

void rpg::from_json(const json& j, Scripts& o)
{
    JSON_GET(Scripts);
}
