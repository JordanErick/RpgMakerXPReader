#pragma once

#include "../utility.hpp"

namespace rpg
{
    class Color
    {
    public:
                    Color();
                    Color(double red, double green, double blue, double alpha);

        double      red() const;
        double      green() const;
        double      blue() const;
        double      alpha() const;

        bool        operator==(const Color& other) const;
        bool        operator!=(const Color& other) const;
        bool        operator<(const Color& other) const;
    private:
        double      mRed;
        double      mGreen;
        double      mBlue;
        double      mAlpha;

        friend void to_json(json& j, const Color& o);
        friend void from_json(const json& j, Color& o);
    };

    void to_json(json& j, const Color& o);
    void from_json(const json& j, Color& o);
}