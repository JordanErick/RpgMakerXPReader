#include "reader/types/armors.hpp"

rpg::Armors::Armors()
: mArmors{}
{
}

rpg::Armors::Armors(const Array& array)
: mArmors{}
{
    // Skip first element which seems to be equal to null all the time
    for (size_t i = 1; i < array.size(); i++)
    {
        const auto& element = array.at(i);

        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Object>()->className() != "RPG::Armor")
            throw std::runtime_error(fmt::format("Invalid class name: {}", element.as<Object>()->className()));

        mArmors.push_back(Armor{ *element.as<Object>() });
    }
}

rpg::Armor& rpg::Armors::operator[](size_t index)
{
    return mArmors[index];
}

const rpg::Armor& rpg::Armors::operator[](size_t index) const
{
    return mArmors.at(index);
}

std::vector<rpg::Armor>::iterator rpg::Armors::begin()
{
    return mArmors.begin();
}

std::vector<rpg::Armor>::const_iterator rpg::Armors::begin() const
{
    return mArmors.begin();
}

std::vector<rpg::Armor>::iterator rpg::Armors::end()
{
    return mArmors.end();
}

std::vector<rpg::Armor>::const_iterator rpg::Armors::end() const
{
    return mArmors.end();
}

bool rpg::Armors::operator==(const Armors& other) const
{
    return mArmors == other.mArmors;
}

bool rpg::Armors::operator!=(const Armors& other) const
{
    return !operator==(other);
}

bool rpg::Armors::operator<(const Armors& other) const
{
    return mArmors < other.mArmors;
}

size_t rpg::Armors::size() const
{
    return mArmors.size();
}

void rpg::to_json(json& j, const Armors& o)
{
    j = json{ JSON_SET(Armors) };
}

void rpg::from_json(const json& j, Armors& o)
{
    JSON_GET(Armors);
}
