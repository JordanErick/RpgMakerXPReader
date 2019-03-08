#include "color.hpp"

bool Color::operator==(const Color & other) const
{
	return red == other.red
		&& green == other.green
		&& blue == other.blue
		&& alpha == other.alpha;
}

bool Color::operator!=(const Color & other) const
{
	return !operator==(other);
}

bool Color::operator<(const Color & other) const
{
	return red + green + blue + alpha < other.red + other.green + other.blue + other.alpha;
}