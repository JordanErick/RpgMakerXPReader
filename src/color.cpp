#include "color.hpp"

Color::Color(double red, double green, double blue, double alpha)
: mRed{red}
, mGreen{green}
, mBlue{blue}
, mAlpha{alpha}
{
}

double Color::red() const
{
	return mRed;
}

double Color::green() const
{
	return mGreen;
}

double Color::blue() const
{
	return mBlue;
}

double Color::alpha() const
{
	return mAlpha;
}

bool Color::operator==(const Color& other) const
{
	return mRed == other.mRed
		&& mGreen == other.mGreen
		&& mBlue == other.mBlue
		&& mAlpha == other.mAlpha;
}

bool Color::operator!=(const Color& other) const
{
	return !operator==(other);
}

bool Color::operator<(const Color& other) const
{
	return mRed + mGreen + mBlue + mAlpha < other.mRed + other.mGreen + other.mBlue + other.mAlpha;
}