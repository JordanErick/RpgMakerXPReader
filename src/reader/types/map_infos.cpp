#include "reader/types/map_infos.hpp"

rpg::MapInfos::MapInfos()
: mMapInfos{}
{
}

rpg::MapInfos::MapInfos(const Hash& hash)
: mMapInfos{}
{
    for (const auto& pair : hash)
    {
        auto key = pair.first;
        auto value = pair.second;

        if (key.type() != Type::Int)
            throw std::runtime_error(fmt::format("Invalid key type: {}", key.type()));

        if (value.type() != Type::Object)
            throw std::runtime_error(fmt::format("Invalid value type: {}", key.type()));

        if (value.as<Object>()->className() != "RPG::MapInfo")
            throw std::runtime_error(fmt::format("Invalid value class name: {}", value.as<Object>()->className()));

        mMapInfos.insert({ *key.as<i32>(), MapInfo{*value.as<Object>()} });
    }
}

rpg::MapInfo& rpg::MapInfos::operator[](i32 key)
{
    return mMapInfos[key];
}

const rpg::MapInfo& rpg::MapInfos::operator[](i32 key) const
{
    return mMapInfos.at(key);
}

std::map<i32, rpg::MapInfo>::iterator rpg::MapInfos::begin()
{
    return mMapInfos.begin();
}

std::map<i32, rpg::MapInfo>::const_iterator rpg::MapInfos::begin() const
{
    return mMapInfos.begin();
}

std::map<i32, rpg::MapInfo>::iterator rpg::MapInfos::end()
{
    return mMapInfos.end();
}

std::map<i32, rpg::MapInfo>::const_iterator rpg::MapInfos::end() const
{
    return mMapInfos.end();
}

bool rpg::MapInfos::operator==(const MapInfos& other) const
{
    return mMapInfos == other.mMapInfos;
}

bool rpg::MapInfos::operator!=(const MapInfos& other) const
{
    return !operator==(other);
}

bool rpg::MapInfos::operator<(const MapInfos& other) const
{
    return mMapInfos < other.mMapInfos;
}

size_t rpg::MapInfos::size() const
{
    return mMapInfos.size();
}

void rpg::to_json(json& j, const MapInfos& o)
{
    j = json{ JSON_SET(MapInfos) };
}

void rpg::from_json(const json& j, MapInfos& o)
{
    JSON_GET(MapInfos);
}
