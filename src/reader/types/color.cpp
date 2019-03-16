#include "reader/types/color.hpp"

rpg::Color::Color()
: mRed{}
, mGreen{}
, mBlue{}
, mAlpha{}
{
}

rpg::Color::Color(double red, double green, double blue, double alpha)
: mRed{red}
, mGreen{green}
, mBlue{blue}
, mAlpha{alpha}
{
}

double rpg::Color::red() const
{
    return mRed;
}

double rpg::Color::green() const
{
    return mGreen;
}

double rpg::Color::blue() const
{
    return mBlue;
}

double rpg::Color::alpha() const
{
    return mAlpha;
}

bool rpg::Color::operator==(const Color& other) const
{
    return mRed == other.mRed
        && mGreen == other.mGreen
        && mBlue == other.mBlue
        && mAlpha == other.mAlpha;
}

bool rpg::Color::operator!=(const Color& other) const
{
    return !operator==(other);
}

bool rpg::Color::operator<(const Color& other) const
{
    return mRed + mGreen + mBlue + mAlpha < other.mRed + other.mGreen + other.mBlue + other.mAlpha;
}

void rpg::to_json(json& j, const Color& o)
{
    j = json{
        JSON_SET(Red),
        JSON_SET(Green),
        JSON_SET(Blue),
        JSON_SET(Alpha)
    };
}

void rpg::from_json(const json& j, Color& o)
{
    JSON_GET(Red);
    JSON_GET(Green);
    JSON_GET(Blue);
    JSON_GET(Alpha);
}
