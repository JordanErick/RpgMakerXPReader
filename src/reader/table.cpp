#include "reader/table.hpp"
#include "reader/tone.hpp"

rpg::Table::Table()
: mDimensions{}
, mXSize{}
, mYSize{}
, mZSize{}
, mTotalSize{}
, mData{}
{
}

rpg::Table::Table(i32 dimensions, i32 xSize, i32 ySize, i32 zSize, i32 totalSize, const std::vector<i16>& data)
: mDimensions{ dimensions }
, mXSize{ xSize }
, mYSize{ ySize }
, mZSize{ zSize }
, mTotalSize{ totalSize }
, mData{ data }
{
}

i32 rpg::Table::dimensions() const
{
    return mDimensions;
}

i32 rpg::Table::xSize() const
{
    return mXSize;
}

i32 rpg::Table::ySize() const
{
    return mYSize;
}

i32 rpg::Table::zSize() const
{
    return mZSize;
}

i32 rpg::Table::totalSize() const
{
    return mTotalSize;
}

const std::vector<i16>& rpg::Table::data() const
{
    return mData;
}

bool rpg::Table::operator==(const Table& other) const
{
    return mDimensions == other.mDimensions
        && mXSize == other.mXSize
        && mYSize == other.mYSize
        && mZSize == other.mZSize
        && mTotalSize == other.mTotalSize
        && mData == other.mData;
}

bool rpg::Table::operator!=(const Table& other) const
{
    return !operator==(other);
}

bool rpg::Table::operator<(const Table& other) const
{
    return mData < other.mData;
}

void rpg::to_json(json& j, const Table& o)
{
    j = json{
        JSON_SET(Dimensions),
        JSON_SET(XSize),
        JSON_SET(YSize),
        JSON_SET(ZSize),
        JSON_SET(TotalSize),
        JSON_SET(Data),
    };
}

void rpg::from_json(const json& j, Table& o)
{
    JSON_GET(Dimensions);
    JSON_GET(XSize);
    JSON_GET(YSize);
    JSON_GET(ZSize);
    JSON_GET(TotalSize);
    JSON_GET(Data);
}
