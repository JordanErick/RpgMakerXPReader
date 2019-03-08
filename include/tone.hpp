#pragma once

struct Tone
{
	double red;
	double green;
	double blue;
	double grey;

	bool operator==(const Tone& other) const;
	bool operator!=(const Tone& other) const;
	bool operator<(const Tone& other) const;
};