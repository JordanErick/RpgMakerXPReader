#include "reader/types/weapons.hpp"

rpg::Weapons::Weapons()
: mWeapons{}
{
}

rpg::Weapons::Weapons(const Array& array)
: mWeapons{}
{
    // Skip first element which seems to be equal to null all the time
    for (size_t i = 1; i < array.size(); i++)
    {
        const auto& element = array.at(i);

        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Object>()->className() != "RPG::Weapon")
            throw std::runtime_error(fmt::format("Invalid class name: {}", element.as<Object>()->className()));

        mWeapons.push_back(Weapon{ *element.as<Object>() });
    }
}

rpg::Weapon& rpg::Weapons::operator[](size_t index)
{
    return mWeapons[index];
}

const rpg::Weapon& rpg::Weapons::operator[](size_t index) const
{
    return mWeapons.at(index);
}

std::vector<rpg::Weapon>::iterator rpg::Weapons::begin()
{
    return mWeapons.begin();
}

std::vector<rpg::Weapon>::const_iterator rpg::Weapons::begin() const
{
    return mWeapons.begin();
}

std::vector<rpg::Weapon>::iterator rpg::Weapons::end()
{
    return mWeapons.end();
}

std::vector<rpg::Weapon>::const_iterator rpg::Weapons::end() const
{
    return mWeapons.end();
}

bool rpg::Weapons::operator==(const Weapons& other) const
{
    return mWeapons == other.mWeapons;
}

bool rpg::Weapons::operator!=(const Weapons& other) const
{
    return !operator==(other);
}

bool rpg::Weapons::operator<(const Weapons& other) const
{
    return mWeapons < other.mWeapons;
}

size_t rpg::Weapons::size() const
{
    return mWeapons.size();
}

void rpg::to_json(json& j, const Weapons& o)
{
    j = json{ JSON_SET(Weapons) };
}

void rpg::from_json(const json& j, Weapons& o)
{
    JSON_GET(Weapons);
}
