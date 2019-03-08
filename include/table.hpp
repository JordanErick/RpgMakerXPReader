#pragma once

#include "utility.hpp"

struct Table
{
	i32 dimensions;
	i32 xSize;
	i32 ySize;
	i32 zSize;
	i32 totalSize;
	std::vector<i16> data;

	bool operator==(const Table& other) const;
	bool operator!=(const Table& other) const;
	bool operator<(const Table& other) const;
};