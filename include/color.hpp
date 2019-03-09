#pragma once

class Color
{
public:
           Color();
           Color(double red, double green, double blue, double alpha);

    double red() const;
    double green() const;
    double blue() const;
    double alpha() const;

    bool   operator==(const Color& other) const;
    bool   operator!=(const Color& other) const;
    bool   operator<(const Color& other) const;
private:
    double mRed;
    double mGreen;
    double mBlue;
    double mAlpha;
};