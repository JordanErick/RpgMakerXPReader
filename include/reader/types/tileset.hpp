#pragma once

#include "../object.hpp"
#include "table.hpp"

namespace rpg
{
    class Tileset
    {
    public:
                                        Tileset();
                                        Tileset(const Object& object);

        const std::vector<std::string>& autotileNames() const;
        const std::string&              battlebackName() const;
        i32                             fogBlendType() const;
        i32                             fogHue() const;
        const std::string&              fogName() const;
        i32                             fogOpacity() const;
        i32                             fogSpeedX() const;
        i32                             fogSpeedY() const;
        i32                             fogZoom() const;
        i32                             ID() const;
        const std::string&              name() const;
        i32                             panoramaHue() const;
        const std::string&              panoramaName() const;
        const Table&                    passages() const;
        const Table&                    priorities() const;
        const Table&                    terrainTags() const;
        const std::string&              tilesetName() const;

        bool                            operator==(const Tileset& other) const;
        bool                            operator!=(const Tileset& other) const;
        bool                            operator<(const Tileset& other) const;
    private:
        std::vector<std::string>        mAutotileNames;
        std::string                     mBattlebackName;
        i32                             mFogBlendType;
        i32                             mFogHue;
        std::string                     mFogName;
        i32                             mFogOpacity;
        i32                             mFogSpeedX;
        i32                             mFogSpeedY;
        i32                             mFogZoom;
        i32                             mID;
        std::string                     mName;
        i32                             mPanoramaHue;
        std::string                     mPanoramaName;
        Table                           mPassages;
        Table                           mPriorities;
        Table                           mTerrainTags;
        std::string                     mTilesetName;

        friend void                     to_json(json& j, const Tileset& o);
        friend void                     from_json(const json& j, Tileset& o);
    };

    void to_json(json& j, const Tileset& o);
    void from_json(const json& j, Tileset& o);
}