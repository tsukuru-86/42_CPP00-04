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
Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result;

	result._raw = _raw + rhs._raw;
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result;

	result._raw = _raw - rhs._raw;
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	const long scale = 1L << _fracBits;
	const long product = static_cast<long>(_raw) * rhs._raw;
	Fixed result;

	if (product >= 0)
		result._raw = static_cast<int>((product + scale / 2) / scale);
	else
		result._raw = static_cast<int>((product - scale / 2) / scale);
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	const long numerator = static_cast<long>(_raw) * (1L << _fracBits);
	const long denominator = rhs._raw;
	long quotient = numerator / denominator;
	const long remainder = numerator % denominator;
	const long absoluteRemainder = remainder < 0 ? -remainder : remainder;
	const long absoluteDenominator = denominator < 0 ? -denominator : denominator;
	Fixed result;

	if (absoluteRemainder * 2 >= absoluteDenominator)
		quotient += ((numerator < 0) != (denominator < 0)) ? -1 : 1;
	result._raw = static_cast<int>(quotient);
	return (result);
}

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
