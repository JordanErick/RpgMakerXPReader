#pragma once

#include "../utility.hpp"

namespace rpg
{
    class Table
    {
    public:
                                         Table() {}
                                         Table(i32 dimensions, i32 xSize, i32 ySize, i32 zSize, i32 totalSize);
                                         Table(i32 dimensions, i32 xSize, i32 ySize, i32 zSize, i32 totalSize, const std::vector<i16>& data);

        i16&                             operator[](size_t index);
        const i16&                       operator[](size_t index) const;

        std::vector<i16>::iterator       begin();
        std::vector<i16>::const_iterator begin() const;

        std::vector<i16>::iterator       end();
        std::vector<i16>::const_iterator end() const;

        i32                              dimensions() const { return mDimensions; }
        i32                              xSize() const { return mXSize; }
        i32                              ySize() const { return mYSize; }
        i32                              zSize() const { return mZSize; }
        i32                              totalSize() const { return mTotalSize; }
        const std::vector<i16>&          data() const { return mData; }

        bool                             operator==(const Table& other) const;
        bool                             operator!=(const Table& other) const;
        bool                             operator<(const Table& other) const;

        size_t                           size() const;
    private:
        i32                              mDimensions = 0;
        i32                              mXSize = 0;
        i32                              mYSize = 0;
        i32                              mZSize = 0;
        i32                              mTotalSize = 0;
        std::vector<i16>                 mData = {};

        friend void                      to_json(json& j, const Table& o);
        friend void                      from_json(const json& j, Table& o);
    };

    void to_json(json& j, const Table& o);
    void from_json(const json& j, Table& o);
}