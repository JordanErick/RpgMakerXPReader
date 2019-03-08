#include "table.hpp"

bool Table::operator==(const Table& other) const
{
	return dimensions == other.dimensions
		&& xSize == other.xSize
		&& ySize == other.ySize
		&& zSize == other.zSize
		&& totalSize == other.totalSize
		&& data == other.data;
}

bool Table::operator!=(const Table& other) const
{
	return !operator==(other);
}

bool Table::operator<(const Table& other) const
{
	return data < other.data;
}