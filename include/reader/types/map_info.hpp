#pragma once

#include "audio_file.hpp"

namespace rpg
{
    class MapInfo
    {
    public:
                           MapInfo();
                           MapInfo(const Object& object);

        bool               expanded() const;
        const std::string& name() const;
        i32                order() const;
        i32                parentID() const;
        i32                scrollX() const;
        i32                scrollY() const;

        bool               operator==(const MapInfo& other) const;
        bool               operator!=(const MapInfo& other) const;
        bool               operator<(const MapInfo& other) const;
    private:
        bool               mExpanded;
        std::string        mName;
        i32                mOrder;
        i32                mParentID;
        i32                mScrollX;
        i32                mScrollY;

        friend void        to_json(json& j, const MapInfo& o);
        friend void        from_json(const json& j, MapInfo& o);
    };

    void to_json(json& j, const MapInfo& o);
    void from_json(const json& j, MapInfo& o);
}