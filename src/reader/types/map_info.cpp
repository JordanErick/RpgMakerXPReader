#include "reader/types/map_info.hpp"

rpg::MapInfo::MapInfo()
: mExpanded{}
, mName{}
, mOrder{}
, mParentID{}
, mScrollX{}
, mScrollY{}
{
}

rpg::MapInfo::MapInfo(const Object& object)
: mExpanded{}
, mName{}
, mOrder{}
, mParentID{}
, mScrollX{}
, mScrollY{}
{
    if (object.className() != "RPG::MapInfo")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mExpanded = *object["@expanded"].as<bool>();
    mName = *object["@name"].as<std::string>();
    mOrder = *object["@order"].as<i32>();
    mParentID = *object["@parent_id"].as<i32>();
    mScrollX = *object["@scroll_x"].as<i32>();
    mScrollY = *object["@scroll_y"].as<i32>();
}

bool rpg::MapInfo::expanded() const
{
    return mExpanded;
}

const std::string& rpg::MapInfo::name() const
{
    return mName;
}

i32 rpg::MapInfo::order() const
{
    return mOrder;
}

i32 rpg::MapInfo::parentID() const
{
    return mParentID;
}

i32 rpg::MapInfo::scrollX() const
{
    return mScrollX;
}

i32 rpg::MapInfo::scrollY() const
{
    return mScrollY;
}

bool rpg::MapInfo::operator==(const MapInfo& other) const
{
    return mOrder == other.mOrder;
}

bool rpg::MapInfo::operator!=(const MapInfo& other) const
{
    return !operator==(other);
}

bool rpg::MapInfo::operator<(const MapInfo& other) const
{
    return mOrder < other.mOrder;
}

void rpg::to_json(json& j, const MapInfo& o)
{
    j = json{
        JSON_SET(Expanded),
        JSON_SET(Name),
        JSON_SET(Order),
        JSON_SET(ParentID),
        JSON_SET(ScrollX),
        JSON_SET(ScrollY)
    };
}

void rpg::from_json(const json& j, MapInfo& o)
{
    JSON_GET(Expanded);
    JSON_GET(Name);
    JSON_GET(Order);
    JSON_GET(ParentID);
    JSON_GET(ScrollX);
    JSON_GET(ScrollY);
}
