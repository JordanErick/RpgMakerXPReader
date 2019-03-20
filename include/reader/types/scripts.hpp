#pragma once

#include "script.hpp"

namespace rpg
{
    class Scripts
    {
    public:
                                            Scripts();
                                            Scripts(const Array& array);

        Script&                             operator[](size_t index);
        const Script&                       operator[](size_t index) const;

        std::vector<Script>::iterator       begin();
        std::vector<Script>::const_iterator begin() const;

        std::vector<Script>::iterator       end();
        std::vector<Script>::const_iterator end() const;

        bool                                operator==(const Scripts& other) const;
        bool                                operator!=(const Scripts& other) const;
        bool                                operator<(const Scripts& other) const;

        size_t                              size() const;
    private:
        std::vector<Script>                 mScripts;

        friend void                         to_json(json& j, const Scripts& o);
        friend void                         from_json(const json& j, Scripts& o);
    };

    void to_json(json& j, const Scripts& o);
    void from_json(const json& j, Scripts& o);
}