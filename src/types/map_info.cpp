#include "types\map_info.hpp"

MapInfo::MapInfo()
: mExpanded{}
, mName{}
, mOrder{}
, mParentID{}
, mScrollX{}
, mScrollY{}
{
}

MapInfo::MapInfo(const Object& object)
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

bool MapInfo::expanded() const
{
    return mExpanded;
}

const std::string& MapInfo::name() const
{
    return mName;
}

i32 MapInfo::order() const
{
    return mOrder;
}

i32 MapInfo::parentID() const
{
    return mParentID;
}

i32 MapInfo::scrollX() const
{
    return mScrollX;
}

i32 MapInfo::scrollY() const
{
    return mScrollY;
}

bool MapInfo::operator==(const MapInfo& other) const
{
    return mOrder == other.mOrder;
}

bool MapInfo::operator!=(const MapInfo& other) const
{
    return !operator==(other);
}

bool MapInfo::operator<(const MapInfo& other) const
{
    return mOrder < other.mOrder;
}

void to_json(json& j, const MapInfo& o)
{
    j = json{
        {"expanded",  o.mExpanded},
        {"name",      o.mName},
        {"order",     o.mOrder},
        {"parent_id", o.mParentID},
        {"scroll_x",  o.mScrollX},
        {"scroll_y",  o.mScrollY},
    };
}

void from_json(const json& j, MapInfo& o)
{
    j.at("expanded").get_to(o.mExpanded);
    j.at("name").get_to(o.mName);
    j.at("order").get_to(o.mOrder);
    j.at("parent_id").get_to(o.mParentID);
    j.at("scroll_x").get_to(o.mScrollX);
    j.at("scroll_y").get_to(o.mScrollY);
}
