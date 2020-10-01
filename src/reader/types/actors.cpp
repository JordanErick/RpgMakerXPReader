#include "reader/types/actors.hpp"

rpg::Actors::Actors(const Array& array)
{
    // Skip first element which seems to be equal to null all the time
    for (size_t i = 1; i < array.size(); i++)
    {
        const auto& element = array.at(i);

        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Object>()->className() != "RPG::Actor")
            throw std::runtime_error(fmt::format("Invalid class name: {}", element.as<Object>()->className()));

        mActors.push_back(Actor{ *element.as<Object>() });
    }
}

rpg::Actor& rpg::Actors::operator[](size_t index)
{
    return mActors[index];
}

const rpg::Actor& rpg::Actors::operator[](size_t index) const
{
    return mActors.at(index);
}

std::vector<rpg::Actor>::iterator rpg::Actors::begin()
{
    return mActors.begin();
}

std::vector<rpg::Actor>::const_iterator rpg::Actors::begin() const
{
    return mActors.begin();
}

std::vector<rpg::Actor>::iterator rpg::Actors::end()
{
    return mActors.end();
}

std::vector<rpg::Actor>::const_iterator rpg::Actors::end() const
{
    return mActors.end();
}

bool rpg::Actors::operator==(const Actors& other) const
{
    return mActors == other.mActors;
}

bool rpg::Actors::operator!=(const Actors& other) const
{
    return !operator==(other);
}

bool rpg::Actors::operator<(const Actors& other) const
{
    return mActors < other.mActors;
}

size_t rpg::Actors::size() const
{
    return mActors.size();
}

void rpg::to_json(json& j, const Actors& o)
{
    j = json{ JSON_SET(Actors) };
}

void rpg::from_json(const json& j, Actors& o)
{
    JSON_GET(Actors);
}
