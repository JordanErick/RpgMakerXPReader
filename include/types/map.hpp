#pragma once

#include "common.hpp"

class Map
{
public:
                     Map();
                     Map(const Object& object);

    bool             autoplayBGM() const;
    bool             autoplayBGS() const;
    const AudioFile& BGM() const;
    const AudioFile& BGS() const;
    const Table&     data() const;
    i32              encounterStep() const;
    i32              height() const;
    i32              tilesetID() const;
    i32              width() const;

private:
    bool             mAutoplayBGM;
    bool             mAutoplayBGS;
    AudioFile        mBGM;
    AudioFile        mBGS;
    Table            mData;
    i32              mEncounterStep;
    i32              mHeight;
    i32              mTilesetID;
    i32              mWidth;
};