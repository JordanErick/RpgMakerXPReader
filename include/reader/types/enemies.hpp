#pragma once

#include "enemy.hpp"

namespace rpg
{
    class Enemies
    {
    public:
                                           Enemies();
                                           Enemies(const Array& array);

        Enemy&                             operator[](size_t index);
        const Enemy&                       operator[](size_t index) const;

        std::vector<Enemy>::iterator       begin();
        std::vector<Enemy>::const_iterator begin() const;

        std::vector<Enemy>::iterator       end();
        std::vector<Enemy>::const_iterator end() const;

        bool                               operator==(const Enemies& other) const;
        bool                               operator!=(const Enemies& other) const;
        bool                               operator<(const Enemies& other) const;

        size_t                             size() const;
    private:
        std::vector<Enemy>                 mEnemies;

        friend void                        to_json(json& j, const Enemies& o);
        friend void                        from_json(const json& j, Enemies& o);
    };

    void to_json(json& j, const Enemies& o);
    void from_json(const json& j, Enemies& o);
}