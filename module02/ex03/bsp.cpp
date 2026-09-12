#include "Point.hpp"

static long crossProduct(const Point& a, const Point& b, const Point& point) {
	const long ax = a.getX().getRawBits();
	const long ay = a.getY().getRawBits();
	const long bx = b.getX().getRawBits();
	const long by = b.getY().getRawBits();
	const long px = point.getX().getRawBits();
	const long py = point.getY().getRawBits();

	return ((bx - ax) * (py - ay) - (by - ay) * (px - ax));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	const long ab = crossProduct(a, b, point);
	const long bc = crossProduct(b, c, point);
	const long ca = crossProduct(c, a, point);

	if (ab == 0 || bc == 0 || ca == 0)
		return (false);
	const bool hasNegative = ab < 0 || bc < 0 || ca < 0;
	const bool hasPositive = ab > 0 || bc > 0 || ca > 0;
	return (!(hasNegative && hasPositive));
}
