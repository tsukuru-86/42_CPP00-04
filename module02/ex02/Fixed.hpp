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

    // Conversions
    Fixed(int value);
    Fixed(float value);

    float toFloat(void) const;
    int   toInt(void) const;

    // Raw access
    int  getRawBits(void) const;
    void setRawBits(int const raw);

    // Comparisons
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Arithmetic
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // Increment / Decrement
    Fixed& operator++();    // pre-increment
    Fixed  operator++(int); // post-increment
    Fixed& operator--();    // pre-decrement
    Fixed  operator--(int); // post-decrement

    // Min / Max
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int _raw;
    static const int _fracBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif // FIXED_HPP

