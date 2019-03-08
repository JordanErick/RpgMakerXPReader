#include "tone.hpp"

bool Tone::operator==(const Tone& other) const
{
	return red == other.red
		&& green == other.green
		&& blue == other.blue
		&& grey == other.grey;
}

bool Tone::operator!=(const Tone& other) const
{
	return !operator==(other);
}

bool Tone::operator<(const Tone& other) const
{
	return red + green + blue + grey < other.red + other.green + other.blue + other.grey;
}