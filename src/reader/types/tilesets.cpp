#include "reader/types/tilesets.hpp"

rpg::Tilesets::Tilesets()
: mTilesets{}
{
}

rpg::Tilesets::Tilesets(const Array& array)
: mTilesets{}
{
    // Skip first element which seems to be equal to null all the time
    for (size_t i = 1; i < array.size(); i++)
    {
        const auto& element = array.at(i);

        if (element.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid any type: {}", element.type()));

        if (element.as<Object>()->className() != "RPG::Tileset")
            throw std::runtime_error(fmt::format("Invalid class name: {}", element.as<Object>()->className()));

        mTilesets.push_back(Tileset{ *element.as<Object>() });
    }
}

rpg::Tileset& rpg::Tilesets::operator[](size_t index)
{
    return mTilesets[index];
}

const rpg::Tileset& rpg::Tilesets::operator[](size_t index) const
{
    return mTilesets.at(index);
}

std::vector<rpg::Tileset>::iterator rpg::Tilesets::begin()
{
    return mTilesets.begin();
}

std::vector<rpg::Tileset>::const_iterator rpg::Tilesets::begin() const
{
    return mTilesets.begin();
}

std::vector<rpg::Tileset>::iterator rpg::Tilesets::end()
{
    return mTilesets.end();
}

std::vector<rpg::Tileset>::const_iterator rpg::Tilesets::end() const
{
    return mTilesets.end();
}

bool rpg::Tilesets::operator==(const Tilesets& other) const
{
    return mTilesets == other.mTilesets;
}

bool rpg::Tilesets::operator!=(const Tilesets& other) const
{
    return !operator==(other);
}

bool rpg::Tilesets::operator<(const Tilesets& other) const
{
    return mTilesets < other.mTilesets;
}

size_t rpg::Tilesets::size() const
{
    return mTilesets.size();
}

void rpg::to_json(json& j, const Tilesets& o)
{
    j = json{ JSON_SET(Tilesets) };
}

void rpg::from_json(const json& j, Tilesets& o)
{
    JSON_GET(Tilesets);
}
