#include "types/map.hpp"

Map::Map()
: mAutoplayBGM{}
, mAutoplayBGS{}
, mBGM{}
, mBGS{}
, mData{}
, mEncounterStep{}
, mHeight{}
, mTilesetID{}
, mWidth{}
{
}

Map::Map(const Object& object)
: mAutoplayBGM{}
, mAutoplayBGS{}
, mBGM{}
, mBGS{}
, mData{}
, mEncounterStep{}
, mHeight{}
, mTilesetID{}
, mWidth{}
{
    if (object.className() != "RPG::Map")
        throw std::runtime_error(fmt::format("Invalid class name: {}", object.className()));

    mAutoplayBGM = *object["@autoplay_bgm"].as<bool>();
    mAutoplayBGS = *object["@autoplay_bgs"].as<bool>();
    mBGM.load(*object["@bgm"].as<Object>());
    mBGS.load(*object["@bgs"].as<Object>());
    mData = *object["@data"].as<Table>();
    mEncounterStep = *object["@encounter_step"].as<i32>();
    mHeight = *object["@height"].as<i32>();
    mTilesetID = *object["@tileset_id"].as<i32>();
    mWidth = *object["@width"].as<i32>();
}

bool Map::autoplayBGM() const
{
    return mAutoplayBGM;
}

bool Map::autoplayBGS() const
{
    return mAutoplayBGS;
}

const AudioFile& Map::BGM() const
{
    return mBGM;
}

const AudioFile& Map::BGS() const
{
    return mBGS;
}

const Table& Map::data() const
{
    return mData;
}

i32 Map::encounterStep() const
{
    return mEncounterStep;
}

i32 Map::height() const
{
    return mHeight;
}

i32 Map::tilesetID() const
{
    return mTilesetID;
}

i32 Map::width() const
{
    return mWidth;
}

void to_json(json& j, const Map& o)
{
    j = json{
        JSON_SET(AutoplayBGM),
        JSON_SET(AutoplayBGS),
        JSON_SET(BGM),
        JSON_SET(BGS),
        JSON_SET(Data),
        JSON_SET(EncounterStep),
        JSON_SET(Height),
        JSON_SET(TilesetID),
        JSON_SET(Width)
    };
}

void from_json(const json& j, Map& o)
{
    JSON_GET(AutoplayBGM);
    JSON_GET(AutoplayBGS);
    JSON_GET(BGM);
    JSON_GET(BGS);
    JSON_GET(Data);
    JSON_GET(EncounterStep);
    JSON_GET(Height);
    JSON_GET(TilesetID);
    JSON_GET(Width);
}
