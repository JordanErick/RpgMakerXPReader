#include "types/items.hpp"

Items::Items(const Array& array)
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

Item& Items::operator[](size_t index)
{
    return mItems[index];
}

std::vector<Item>::iterator Items::begin()
{
    return mItems.begin();
}

std::vector<Item>::const_iterator Items::begin() const
{
    return mItems.begin();
}

std::vector<Item>::iterator Items::end()
{
    return mItems.end();
}

std::vector<Item>::const_iterator Items::end() const
{
    return mItems.end();
}

bool Items::operator==(const Items& other) const
{
    return mItems == other.mItems;
}

bool Items::operator!=(const Items& other) const
{
    return !operator==(other);
}

bool Items::operator<(const Items & other) const
{
    return mItems < other.mItems;
}

size_t Items::size()
{
    return mItems.size();
}
