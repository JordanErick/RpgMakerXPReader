#include "common.hpp"

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
};