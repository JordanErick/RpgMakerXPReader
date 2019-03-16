#include "reader/types/states.hpp"

rpg::States::States()
: mStates{}
{
}

rpg::States::States(const Array& array)
: mStates{}
{
    // Skip first element which seems to be equal to null all the time
    for (size_t i = 1; i < array.size(); i++)
    {
        const auto& element = array.at(i);

        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Object>()->className() != "RPG::State")
            throw std::runtime_error(fmt::format("Invalid class name: {}", element.as<Object>()->className()));

        mStates.push_back(State{ *element.as<Object>() });
    }
}

rpg::State& rpg::States::operator[](size_t index)
{
    return mStates[index];
}

const rpg::State& rpg::States::operator[](size_t index) const
{
    return mStates.at(index);
}

std::vector<rpg::State>::iterator rpg::States::begin()
{
    return mStates.begin();
}

std::vector<rpg::State>::const_iterator rpg::States::begin() const
{
    return mStates.begin();
}

std::vector<rpg::State>::iterator rpg::States::end()
{
    return mStates.end();
}

std::vector<rpg::State>::const_iterator rpg::States::end() const
{
    return mStates.end();
}

bool rpg::States::operator==(const States& other) const
{
    return mStates == other.mStates;
}

bool rpg::States::operator!=(const States& other) const
{
    return !operator==(other);
}

bool rpg::States::operator<(const States& other) const
{
    return mStates < other.mStates;
}

size_t rpg::States::size() const
{
    return mStates.size();
}

void rpg::to_json(json& j, const States& o)
{
    j = json{ JSON_SET(States) };
}
void rpg::from_json(const json& j, States& o)
{
    JSON_GET(States);
}
