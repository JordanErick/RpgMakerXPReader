#pragma once

#include "weapon.hpp"

namespace rpg
{
    class Weapons
    {
    public:
                                            Weapons();
                                            Weapons(const Array& array);

        Weapon&                             operator[](size_t index);
        const Weapon&                       operator[](size_t index) const;

        std::vector<Weapon>::iterator       begin();
        std::vector<Weapon>::const_iterator begin() const;

        std::vector<Weapon>::iterator       end();
        std::vector<Weapon>::const_iterator end() const;

        bool                                operator==(const Weapons& other) const;
        bool                                operator!=(const Weapons& other) const;
        bool                                operator<(const Weapons& other) const;

        size_t                              size() const;
    private:
        std::vector<Weapon>                 mWeapons;

        friend void                         to_json(json& j, const Weapons& o);
        friend void                         from_json(const json& j, Weapons& o);
    };

    void to_json(json& j, const Weapons& o);
    void from_json(const json& j, Weapons& o);
}