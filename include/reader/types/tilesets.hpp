#pragma once

#include "tileset.hpp"

namespace rpg
{
    class Tilesets
    {
    public:
                                             Tilesets();
                                             Tilesets(const Array& array);

        Tileset&                             operator[](size_t index);
        const Tileset&                       operator[](size_t index) const;

        std::vector<Tileset>::iterator       begin();
        std::vector<Tileset>::const_iterator begin() const;

        std::vector<Tileset>::iterator       end();
        std::vector<Tileset>::const_iterator end() const;

        bool                                 operator==(const Tilesets& other) const;
        bool                                 operator!=(const Tilesets& other) const;
        bool                                 operator<(const Tilesets& other) const;

        size_t                               size() const;
    private:
        std::vector<Tileset>                 mTilesets;

        friend void                          to_json(json& j, const Tilesets& o);
        friend void                          from_json(const json& j, Tilesets& o);
    };

    void to_json(json& j, const Tilesets& o);
    void from_json(const json& j, Tilesets& o);
}