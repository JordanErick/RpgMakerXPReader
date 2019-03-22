#pragma once

#include "armor.hpp"

namespace rpg
{
    class Armors
    {
    public:
                                           Armors() {}
                                           Armors(const Array& array);

        Armor&                             operator[](size_t index);
        const Armor&                       operator[](size_t index) const;

        std::vector<Armor>::iterator       begin();
        std::vector<Armor>::const_iterator begin() const;

        std::vector<Armor>::iterator       end();
        std::vector<Armor>::const_iterator end() const;

        bool                               operator==(const Armors& other) const;
        bool                               operator!=(const Armors& other) const;
        bool                               operator<(const Armors& other) const;

        size_t                             size() const;
    private:
        std::vector<Armor>                 mArmors = {};

        friend void                        to_json(json& j, const Armors& o);
        friend void                        from_json(const json& j, Armors& o);
    };

    void to_json(json& j, const Armors& o);
    void from_json(const json& j, Armors& o);
}