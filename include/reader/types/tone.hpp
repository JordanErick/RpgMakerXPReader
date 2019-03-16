#pragma once

#include "../utility.hpp"

namespace rpg
{
    class Tone
    {
    public:
                    Tone();
                    Tone(double red, double green, double blue, double grey);

        double      red() const;
        double      green() const;
        double      blue() const;
        double      grey() const;

        bool        operator==(const Tone& other) const;
        bool        operator!=(const Tone& other) const;
        bool        operator<(const Tone& other) const;

    private:
        double      mRed;
        double      mGreen;
        double      mBlue;
        double      mGrey;

        friend void to_json(json& j, const Tone& o);
        friend void from_json(const json& j, Tone& o);
    };

    void to_json(json& j, const Tone& o);
    void from_json(const json& j, Tone& o);
}