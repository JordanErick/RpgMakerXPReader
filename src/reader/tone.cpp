#include "reader/tone.hpp"

rpg::Tone::Tone()
: mRed{}
, mGreen{}
, mBlue{}
, mGrey{}
{
}

rpg::Tone::Tone(double red, double green, double blue, double grey)
: mRed{red}
, mGreen{green}
, mBlue{blue}
, mGrey{grey}
{
}

double rpg::Tone::red() const
{
    return mRed;
}

double rpg::Tone::green() const
{
    return mGreen;
}

double rpg::Tone::blue() const
{
    return mBlue;
}

double rpg::Tone::grey() const
{
    return mGrey;
}

bool rpg::Tone::operator==(const Tone& other) const
{
    return mRed == other.mRed
        && mGreen == other.mGreen
        && mBlue == other.mBlue
        && mGrey == other.mGrey;
}

bool rpg::Tone::operator!=(const Tone& other) const
{
    return !operator==(other);
}

bool rpg::Tone::operator<(const Tone& other) const
{
    return mRed + mGreen + mBlue + mGrey < other.mRed + other.mGreen + other.mBlue + other.mGrey;
}

void rpg::to_json(json& j, const Tone& o)
{
    j = json{
        JSON_SET(Red),
        JSON_SET(Green),
        JSON_SET(Blue),
        JSON_SET(Grey)
    };
}

void rpg::from_json(const json& j, Tone& o)
{
    JSON_GET(Red);
    JSON_GET(Green);
    JSON_GET(Blue);
    JSON_GET(Grey);
}