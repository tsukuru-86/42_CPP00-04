#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fracBits = 8;

Fixed::Fixed() : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _raw(0) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_raw = other._raw;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int value) : _raw(value * (1 << _fracBits)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float value)
	: _raw(static_cast<int>(roundf(value * (1 << _fracBits)))) {
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(_raw) / (1 << _fracBits));
}

int Fixed::toInt(void) const {
	return (_raw / (1 << _fracBits));
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_raw);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_raw = raw;
}

bool Fixed::operator>(const Fixed& rhs) const { return (_raw > rhs._raw); }
bool Fixed::operator<(const Fixed& rhs) const { return (_raw < rhs._raw); }
bool Fixed::operator>=(const Fixed& rhs) const { return (_raw >= rhs._raw); }
bool Fixed::operator<=(const Fixed& rhs) const { return (_raw <= rhs._raw); }
bool Fixed::operator==(const Fixed& rhs) const { return (_raw == rhs._raw); }
bool Fixed::operator!=(const Fixed& rhs) const { return (_raw != rhs._raw); }
Fixed Fixed::operator+(const Fixed& rhs) const { return (Fixed(toFloat() + rhs.toFloat())); }
Fixed Fixed::operator-(const Fixed& rhs) const { return (Fixed(toFloat() - rhs.toFloat())); }
Fixed Fixed::operator*(const Fixed& rhs) const { return (Fixed(toFloat() * rhs.toFloat())); }
Fixed Fixed::operator/(const Fixed& rhs) const { return (Fixed(toFloat() / rhs.toFloat())); }

Fixed& Fixed::operator++() { ++_raw; return (*this); }
Fixed Fixed::operator++(int) { Fixed copy(*this); ++_raw; return (copy); }
Fixed& Fixed::operator--() { --_raw; return (*this); }
Fixed Fixed::operator--(int) { Fixed copy(*this); --_raw; return (copy); }

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b ? a : b); }
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b ? a : b); }
Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b ? a : b); }
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b ? a : b); }

std::ostream& operator<<(std::ostream& output, const Fixed& value) {
	output << value.toFloat();
	return (output);
}
