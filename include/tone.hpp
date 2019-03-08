#pragma once

class Tone
{
public:
	Tone();
	Tone(double red, double green, double blue, double grey);

	double red() const;
	double green() const;
	double blue() const;
	double grey() const;
	
	bool operator==(const Tone& other) const;
	bool operator!=(const Tone& other) const;
	bool operator<(const Tone& other) const;

private:
	double mRed;
	double mGreen;
	double mBlue;
	double mGrey;
};