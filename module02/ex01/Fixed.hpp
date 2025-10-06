#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    // Orthodox Canonical Form
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // New in ex01
    Fixed(int value);
    Fixed(float value);

    float toFloat(void) const;
    int   toInt(void) const;

    // From ex00
    int  getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _raw;
    static const int _fracBits;
};

// Insertion operator (non-member)
std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif // FIXED_HPP

