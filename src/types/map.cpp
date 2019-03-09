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
        {"autoplay_bgm", o.mAutoplayBGM},
        {"autoplay_bgs", o.mAutoplayBGS},
        {"bgm", o.mBGM},
        {"bgs", o.mBGS},
        {"data", o.mData},
        {"encounter_step", o.mEncounterStep},
        {"height", o.mHeight},
        {"tileset_id", o.mTilesetID},
        {"width", o.mWidth},
    };
}

void from_json(const json& j, Map& o)
{
    j.at("autoplay_bgm").get_to(o.mAutoplayBGM);
    j.at("autoplay_bgs").get_to(o.mAutoplayBGS);
    j.at("bgm").get_to(o.mBGM);
    j.at("bgs").get_to(o.mBGS);
    j.at("data").get_to(o.mData);
    j.at("encounter_step").get_to(o.mEncounterStep);
    j.at("height").get_to(o.mHeight);
    j.at("tileset_id").get_to(o.mTilesetID);
    j.at("width").get_to(o.mWidth);
}
