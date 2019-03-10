#include "..\..\include\types\armors.hpp"

Armors::Armors()
: mArmors{}
{
}

Armors::Armors(const Array& array)
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

Armor& Armors::operator[](size_t index)
{
    return mArmors[index];
}

const Armor& Armors::operator[](size_t index) const
{
    return mArmors.at(index);
}

std::vector<Armor>::iterator Armors::begin()
{
    return mArmors.begin();
}

std::vector<Armor>::const_iterator Armors::begin() const
{
    return mArmors.begin();
}

std::vector<Armor>::iterator Armors::end()
{
    return mArmors.end();
}

std::vector<Armor>::const_iterator Armors::end() const
{
    return mArmors.end();
}

bool Armors::operator==(const Armors& other) const
{
    return mArmors == other.mArmors;
}

bool Armors::operator!=(const Armors& other) const
{
    return !operator==(other);
}

bool Armors::operator<(const Armors& other) const
{
    return mArmors < other.mArmors;
}

size_t Armors::size() const
{
    return mArmors.size();
}

void to_json(json& j, const Armors& o)
{
    j = json{ {"armors", o.mArmors} };
}

void from_json(const json& j, Armors& o)
{
    j.at("armors").get_to(o.mArmors);
}
