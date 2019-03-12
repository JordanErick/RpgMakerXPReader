#include "types\states.hpp"

States::States()
: mStates{}
{
}

States::States(const Array& array)
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

State& States::operator[](size_t index)
{
    return mStates[index];
}

const State& States::operator[](size_t index) const
{
    return mStates.at(index);
}

std::vector<State>::iterator States::begin()
{
    return mStates.begin();
}

std::vector<State>::const_iterator States::begin() const
{
    return mStates.begin();
}

std::vector<State>::iterator States::end()
{
    return mStates.end();
}

std::vector<State>::const_iterator States::end() const
{
    return mStates.end();
}

bool States::operator==(const States& other) const
{
    return mStates == other.mStates;
}

bool States::operator!=(const States& other) const
{
    return !operator==(other);
}

bool States::operator<(const States& other) const
{
    return mStates < other.mStates;
}

size_t States::size() const
{
    return mStates.size();
}

void to_json(json& j, const States& o)
{
    j = json{ JSON_SET(States) };
}
void from_json(const json& j, States& o)
{
    JSON_GET(States);
}

