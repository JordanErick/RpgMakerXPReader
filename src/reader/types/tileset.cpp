#include "reader/types/tileset.hpp"

rpg::Tileset::Tileset()
: mAutotileNames{}
, mBattlebackName{}
, mFogBlendType{}
, mFogHue{}
, mFogName{}
, mFogOpacity{}
, mFogSpeedX{}
, mFogSpeedY{}
, mFogZoom{}
, mID{}
, mName{}
, mPanoramaHue{}
, mPanoramaName{}
, mPassages{}
, mPriorities{}
, mTerrainTags{}
, mTilesetName{}
{
}

rpg::Tileset::Tileset(const Object& object)
: mAutotileNames{}
, mBattlebackName{}
, mFogBlendType{}
, mFogHue{}
, mFogName{}
, mFogOpacity{}
, mFogSpeedX{}
, mFogSpeedY{}
, mFogZoom{}
, mID{}
, mName{}
, mPanoramaHue{}
, mPanoramaName{}
, mPassages{}
, mPriorities{}
, mTerrainTags{}
, mTilesetName{}
{
    auto* autotileNames = object["@autotile_names"].as<Array>();
    for (const auto& e : *autotileNames)
        mAutotileNames.push_back(*e.as<std::string>());

    mBattlebackName = *object["@battleback_name"].as<std::string>();
    mFogBlendType = *object["@fog_blend_type"].as<i32>();
    mFogHue = *object["@fog_hue"].as<i32>();
    mFogName = *object["@fog_name"].as<std::string>();
    mFogOpacity = *object["@fog_opacity"].as<i32>();
    mFogSpeedX = *object["@fog_sx"].as<i32>();
    mFogSpeedY = *object["@fog_sy"].as<i32>();
    mFogZoom = *object["@fog_zoom"].as<i32>();
    mID = *object["@id"].as<i32>();
    mName = *object["@name"].as<std::string>();
    mPanoramaHue = *object["@panorama_hue"].as<i32>();
    mPanoramaName = *object["@panorama_name"].as<std::string>();
    mPassages = *object["@passages"].as<Table>();
    mPriorities = *object["@priorities"].as<Table>();
    mTerrainTags = *object["@terrain_tags"].as<Table>();
    mTilesetName = *object["@tileset_name"].as<std::string>();
}

const std::vector<std::string>& rpg::Tileset::autotileNames() const
{
    return mAutotileNames;
}

const std::string& rpg::Tileset::battlebackName() const
{
    return mBattlebackName;
}

i32 rpg::Tileset::fogBlendType() const
{
    return mFogBlendType;
}

i32 rpg::Tileset::fogHue() const
{
    return mFogHue;
}

const std::string& rpg::Tileset::fogName() const
{
    return mFogName;
}

i32 rpg::Tileset::fogOpacity() const
{
    return mFogOpacity;
}

i32 rpg::Tileset::fogSpeedX() const
{
    return mFogSpeedX;
}

i32 rpg::Tileset::fogSpeedY() const
{
    return mFogSpeedY;
}

i32 rpg::Tileset::fogZoom() const
{
    return mFogZoom;
}

i32 rpg::Tileset::ID() const
{
    return mID;
}

const std::string& rpg::Tileset::name() const
{
    return mName;
}

i32 rpg::Tileset::panoramaHue() const
{
    return mPanoramaHue;
}

const std::string& rpg::Tileset::panoramaName() const
{
    return mPanoramaName;
}

const rpg::Table& rpg::Tileset::passages() const
{
    return mPassages;
}

const rpg::Table& rpg::Tileset::priorities() const
{
    return mPriorities;
}

const rpg::Table& rpg::Tileset::terrainTags() const
{
    return mTerrainTags;
}

const std::string& rpg::Tileset::tilesetName() const
{
    return mTilesetName;
}

bool rpg::Tileset::operator==(const Tileset& other) const
{
    return mID == other.mID;
}

bool rpg::Tileset::operator!=(const Tileset& other) const
{
    return !operator==(other);
}

bool rpg::Tileset::operator<(const Tileset& other) const
{
    return mID < other.mID;
}

void rpg::to_json(json& j, const Tileset& o)
{
    j = json{
        JSON_SET(AutotileNames),
        JSON_SET(BattlebackName),
        JSON_SET(FogBlendType),
        JSON_SET(FogHue),
        JSON_SET(FogName),
        JSON_SET(FogOpacity),
        JSON_SET(FogSpeedX),
        JSON_SET(FogSpeedY),
        JSON_SET(FogZoom),
        JSON_SET(ID),
        JSON_SET(Name),
        JSON_SET(PanoramaHue),
        JSON_SET(PanoramaName),
        JSON_SET(Passages),
        JSON_SET(Priorities),
        JSON_SET(TerrainTags),
        JSON_SET(TilesetName)
    };
}

void rpg::from_json(const json& j, Tileset& o)
{
    JSON_GET(AutotileNames);
    JSON_GET(BattlebackName);
    JSON_GET(FogBlendType);
    JSON_GET(FogHue);
    JSON_GET(FogName);
    JSON_GET(FogOpacity);
    JSON_GET(FogSpeedX);
    JSON_GET(FogSpeedY);
    JSON_GET(FogZoom);
    JSON_GET(ID);
    JSON_GET(Name);
    JSON_GET(PanoramaHue);
    JSON_GET(PanoramaName);
    JSON_GET(Passages);
    JSON_GET(Priorities);
    JSON_GET(TerrainTags);
    JSON_GET(TilesetName);
}
