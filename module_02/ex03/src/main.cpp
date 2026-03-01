#include <iostream>
#include "Point.hpp"

static void runCase(const char *label, Point const &a, Point const &b, Point const &c,
	Point const &p)
{
	std::cout << label << ": " << std::boolalpha << bsp(a, b, c, p) << std::endl;
}

int main(void)
{
	Point const a(0.0f, 0.0f);
	Point const b(10.0f, 0.0f);
	Point const c(0.0f, 10.0f);

	Point const inside(2.0f, 2.0f);
	Point const outside(10.0f, 10.0f);
	Point const onEdge(5.0f, 0.0f);
	Point const onVertex(0.0f, 0.0f);

	runCase("inside", a, b, c, inside);
	runCase("outside", a, b, c, outside);
	runCase("onEdge", a, b, c, onEdge);
	runCase("onVertex", a, b, c, onVertex);
	return (0);
}
