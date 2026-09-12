#include "Point.hpp"
#include <iostream>

static void testPoint(const Point& a, const Point& b, const Point& c,
	const Point& point, const char *description) {
	const bool isInside = bsp(a, b, c, point);
	std::cout << description << ": "
		<< (isInside ? "inside" : "outside") << std::endl;
}

int main(void) {
	const Point a(0.0f, 0.0f);
	const Point b(10.0f, 0.0f);
	const Point c(0.0f, 10.0f);

	testPoint(a, b, c, Point(2.0f, 2.0f), "interior");
	testPoint(a, b, c, Point(8.0f, 8.0f), "exterior");
	testPoint(a, b, c, Point(5.0f, 0.0f), "edge");
	testPoint(a, b, c, Point(0.0f, 0.0f), "vertex");
	testPoint(a, a, c, Point(0.0f, 1.0f), "degenerate triangle");
	return (0);
}
