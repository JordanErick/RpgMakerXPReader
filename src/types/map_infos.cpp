#include "types\map_infos.hpp"

MapInfos::MapInfos(const Hash& hash)
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

MapInfo& MapInfos::operator[](i32 key)
{
    return mMapInfos[key];
}

const MapInfo& MapInfos::operator[](i32 key) const
{
    return mMapInfos.at(key);
}

std::map<i32, MapInfo>::iterator MapInfos::begin()
{
    return mMapInfos.begin();
}

std::map<i32, MapInfo>::const_iterator MapInfos::begin() const
{
    return mMapInfos.begin();
}

std::map<i32, MapInfo>::iterator MapInfos::end()
{
    return mMapInfos.end();
}

std::map<i32, MapInfo>::const_iterator MapInfos::end() const
{
    return mMapInfos.end();
}

bool MapInfos::operator==(const MapInfos& other) const
{
    return mMapInfos == other.mMapInfos;
}

bool MapInfos::operator!=(const MapInfos& other) const
{
    return !operator==(other);
}

bool MapInfos::operator<(const MapInfos& other) const
{
    return mMapInfos < other.mMapInfos;
}

size_t MapInfos::size() const
{
    return mMapInfos.size();
}

void to_json(json& j, const MapInfos& o)
{
    j = json{ {"map_infos", o.mMapInfos} };
}

void from_json(const json& j, MapInfos& o)
{
    j.at("map_infos").get_to(o.mMapInfos);
}
