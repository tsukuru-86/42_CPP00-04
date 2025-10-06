#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fracBits = 8;

// Canonical
Fixed::Fixed() : _raw(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _raw(0) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_raw = other._raw;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// New in ex01
Fixed::Fixed(int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_raw = value << _fracBits;
}

Fixed::Fixed(float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_raw = static_cast<int>(roundf(value * (1 << _fracBits)));
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_raw) / static_cast<float>(1 << _fracBits);
}

int Fixed::toInt(void) const {
    return this->_raw >> _fracBits;
}

// From ex00
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_raw = raw;
}

// ostream overload
std::ostream& operator<<(std::ostream& os, const Fixed& x) {
    os << x.toFloat();
    return os;
}

