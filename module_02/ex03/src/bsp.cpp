#include "Point.hpp"

static Fixed sign(Point const &p1, Point const &p2, Point const &p3)
{
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const zero(0);
	Fixed const area = sign(a, b, c);
	Fixed const d1 = sign(point, a, b);
	Fixed const d2 = sign(point, b, c);
	Fixed const d3 = sign(point, c, a);
	bool const has_neg = (d1 < zero) || (d2 < zero) || (d3 < zero);
	bool const has_pos = (d1 > zero) || (d2 > zero) || (d3 > zero);

	if (area == zero)
		return (false);
	if (d1 == zero || d2 == zero || d3 == zero)
		return (false);
	return (!(has_neg && has_pos));
}
