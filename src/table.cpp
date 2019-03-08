#include "table.hpp"

Table::Table()
: mDimensions{}
, mXSize{}
, mYSize{}
, mZSize{}
, mTotalSize{}
, mData{}
{
}

Table::Table(i32 dimensions, i32 xSize, i32 ySize, i32 zSize, i32 totalSize, const std::vector<i16>& data)
: mDimensions{ dimensions }
, mXSize{ xSize }
, mYSize{ ySize }
, mZSize{ zSize }
, mTotalSize{ totalSize }
, mData{ data }
{
}

i32 Table::dimensions() const
{
	return mDimensions;
}

i32 Table::xSize() const
{
	return mXSize;
}

i32 Table::ySize() const
{
	return mYSize;
}

i32 Table::zSize() const
{
	return mZSize;
}

i32 Table::totalSize() const
{
	return mTotalSize;
}

const std::vector<i16>& Table::data() const
{
	return mData;
}

bool Table::operator==(const Table& other) const
{
	return mDimensions == other.mDimensions
		&& mXSize == other.mXSize
		&& mYSize == other.mYSize
		&& mZSize == other.mZSize
		&& mTotalSize == other.mTotalSize
		&& mData == other.mData;
}

bool Table::operator!=(const Table& other) const
{
	return !operator==(other);
}

bool Table::operator<(const Table& other) const
{
	return mData < other.mData;
}
