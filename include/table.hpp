#pragma once

#include "utility.hpp"

class Table
{
public:
                            Table();
                            Table(i32 dimensions, i32 xSize, i32 ySize, i32 zSize, i32 totalSize, const std::vector<i16>& data);

    i32                     dimensions() const;
    i32                     xSize() const;
    i32                     ySize() const;
    i32                     zSize() const;
    i32                     totalSize() const;
    const std::vector<i16>& data() const;

    bool                    operator==(const Table& other) const;
    bool                    operator!=(const Table& other) const;
    bool                    operator<(const Table& other) const;
private:
    i32                     mDimensions;
    i32                     mXSize;
    i32                     mYSize;
    i32                     mZSize;
    i32                     mTotalSize;
    std::vector<i16>        mData;

    friend void             to_json(json& j, const Table& o);
    friend void             from_json(const json& j, Table& o);
};

void to_json(json& j, const Table& o);
void from_json(const json& j, Table& o);