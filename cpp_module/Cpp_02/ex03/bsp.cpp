#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (!Point::samPos(a, b, c, point))
		return (false);
	double area = Point::area(a, b, c);
	double area1 = Point::area(a, b, point);
	double area2 = Point::area(a, point, c);
	double area3 = Point::area(point, b, c);
	double tmp = area1 + area2 + area3;
	if (tmp - area > 0)
		return (false);
	else
		return (true);
}