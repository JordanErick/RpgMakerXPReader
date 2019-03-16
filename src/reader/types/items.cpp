#include "reader/types/items.hpp"

rpg::Items::Items()
: mItems{}
{
}

rpg::Items::Items(const Array& array)
: mItems{}
{
    // Skip first element which seems to be equal to null all the time
    for (size_t i = 1; i < array.size(); i++)
    {
        const auto& element = array.at(i);

        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Object>()->className() != "RPG::Item")
            throw std::runtime_error(fmt::format("Invalid class name: {}", element.as<Object>()->className()));

        mItems.push_back(Item{ *element.as<Object>() });
    }
}

rpg::Item& rpg::Items::operator[](size_t index)
{
    return mItems[index];
}

const rpg::Item& rpg::Items::operator[](size_t index) const
{
    return mItems.at(index);
}

std::vector<rpg::Item>::iterator rpg::Items::begin()
{
    return mItems.begin();
}

std::vector<rpg::Item>::const_iterator rpg::Items::begin() const
{
    return mItems.begin();
}

std::vector<rpg::Item>::iterator rpg::Items::end()
{
    return mItems.end();
}

std::vector<rpg::Item>::const_iterator rpg::Items::end() const
{
    return mItems.end();
}

bool rpg::Items::operator==(const Items& other) const
{
    return mItems == other.mItems;
}

bool rpg::Items::operator!=(const Items& other) const
{
    return !operator==(other);
}

bool rpg::Items::operator<(const Items & other) const
{
    return mItems < other.mItems;
}

size_t rpg::Items::size() const
{
    return mItems.size();
}

void rpg::to_json(json& j, const Items& o)
{
    j = json{ JSON_SET(Items) };
}

void rpg::from_json(const json& j, Items& o)
{
    JSON_GET(Items);
}
