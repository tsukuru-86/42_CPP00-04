*This project has been created as part of the 42 curriculum by tkomai.*

# C++ Module 02

## Description

This module introduces fixed-point numbers, ad-hoc polymorphism, operator
overloading, and the Orthodox Canonical Form in C++98.

- `ex00`: canonical `Fixed` class and raw-bit access
- `ex01`: integer/float conversion and stream insertion
- `ex02`: comparisons, arithmetic, increments, decrements, `min`, and `max`
- `ex03`: `Point` and Binary Space Partitioning for point-in-triangle tests

The optional `ex03` is included. A point on an edge or vertex is considered
outside the triangle, as required by the subject.

## Instructions

Build and run an exercise from its directory:

```sh
cd ex02
make
./ex02
```

Use `./ex00` and `./ex01` for the first two exercises, and `./bsp` for
`ex03`. Every Makefile compiles with `-Wall -Wextra -Werror -std=c++98` and
provides the `clean`, `fclean`, and `re` rules.

## Resources

- [C++ Module 02 subject](../CPP_42/C++Module02.pdf)
- [Fixed-point arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
- [Operator overloading](https://en.cppreference.com/w/cpp/language/operators)
- [Canonical class form](https://isocpp.org/wiki/faq/ctors)

AI was used to compare the implementation with the subject, identify and fix
precision loss in fixed-point arithmetic, and design edge-case tests for the
operators and BSP. All changes were reviewed and compiled with the required
C++98 warning flags.
