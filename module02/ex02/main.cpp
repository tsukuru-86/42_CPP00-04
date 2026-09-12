#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    Fixed x(3.5f);
    Fixed y(2);
    std::cout << "comparisons: " << (x > y) << " " << (x < y) << " "
              << (x >= y) << " " << (x <= y) << " " << (x == y) << " "
              << (x != y) << std::endl;
    std::cout << "arithmetic: " << x + y << " " << x - y << " "
              << x * y << " " << x / y << std::endl;
    std::cout << "decrement: " << --x << " " << x-- << " " << x << std::endl;
    std::cout << "min/max: " << Fixed::min(x, y) << " "
              << Fixed::max(x, y) << std::endl;
    const Fixed cx(1);
    const Fixed cy(4);
    std::cout << "const min/max: " << Fixed::min(cx, cy) << " "
              << Fixed::max(cx, cy) << std::endl;
    return 0;
}
