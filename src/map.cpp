#include "..\include\map.hpp"

Map::Map(const Any* any)
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
    if (any->type() != Type::Object)
        throw std::runtime_error(fmt::format("Invalid any type: {}", any->type()));

    if (any->as<Object>()->className() != "RPG::Map")
        throw std::runtime_error(fmt::format("Invalid class name: {}", any->as<Object>()->className()));

    auto* object = any->as<Object>();

    mAutoplayBGM = *(*object)["@autoplay_bgm"].as<bool>();
    mAutoplayBGS = *(*object)["@autoplay_bgs"].as<bool>();
    mBGM.fromAny(&(*object)["@bgm"]);
    mBGS.fromAny(&(*object)["@bgs"]);
    mData = *(*object)["@data"].as<Table>();
    mEncounterStep = *(*object)["@encounter_step"].as<i32>();
    mHeight = *(*object)["@height"].as<i32>();
    mTilesetID = *(*object)["@tileset_id"].as<i32>();
    mWidth = *(*object)["@width"].as<i32>();
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
