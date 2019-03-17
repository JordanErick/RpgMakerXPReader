#pragma once

#include "actor.hpp"

namespace rpg
{
    class Actors
    {
    public:
                                           Actors();
                                           Actors(const Array& array);

        Actor&                             operator[](size_t index);
        const Actor&                       operator[](size_t index) const;

        std::vector<Actor>::iterator       begin();
        std::vector<Actor>::const_iterator begin() const;

        std::vector<Actor>::iterator       end();
        std::vector<Actor>::const_iterator end() const;

        bool                               operator==(const Actors& other) const;
        bool                               operator!=(const Actors& other) const;
        bool                               operator<(const Actors& other) const;

        size_t                             size() const;
    private:
        std::vector<Actor>                 mActors;

        friend void                        to_json(json& j, const Actors& o);
        friend void                        from_json(const json& j, Actors& o);
    };

    void to_json(json& j, const Actors& o);
    void from_json(const json& j, Actors& o);
}