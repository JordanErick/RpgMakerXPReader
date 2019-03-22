#include "reader/types/table.hpp"

rpg::Table::Table(i32 dimensions, i32 xSize, i32 ySize, i32 zSize, i32 totalSize)
: mDimensions{ dimensions }
, mXSize{ xSize }
, mYSize{ ySize }
, mZSize{ zSize }
, mTotalSize{ totalSize }
, mData(totalSize, 0)
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

i16& rpg::Table::operator[](size_t index)
{
    return mData[index];
}

const i16& rpg::Table::operator[](size_t index) const
{
    return mData.at(index);
}

std::vector<i16>::iterator rpg::Table::begin()
{
    return mData.begin();
}

std::vector<i16>::const_iterator rpg::Table::begin() const
{
    return mData.begin();
}

std::vector<i16>::iterator rpg::Table::end()
{
    return mData.end();
}

std::vector<i16>::const_iterator rpg::Table::end() const
{
    return mData.end();
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

size_t rpg::Table::size() const
{
    return mData.size();
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
