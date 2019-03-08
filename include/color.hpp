#pragma once

struct Color
{
	double red;
	double green;
	double blue;
	double alpha;

	bool operator==(const Color& other) const;
	bool operator!=(const Color& other) const;
	bool operator<(const Color& other) const;
};