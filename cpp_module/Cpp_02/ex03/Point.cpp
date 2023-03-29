#include "Point.hpp"

Point::Point() : x(), y()
{

}

Point::Point(float x, float y) : x(x), y(y)
{

}

Point::Point(const Point& c) : x(c.x), y(c.y)
{

}

Point::~Point()
{

}

Point& Point::operator=(Point& c)
{
	return (c);
}

bool Point::getPoint(float& x, float& y) const
{
	x = this->x.toFloat();
	y = this->y.toFloat();
	return (1);
}


double Point::area(Point a, Point b, Point c)
{
	float aX, aY, bX, bY, cX, cY = 0;
	a.getPoint(aX, aY);
	b.getPoint(bX, bY);
	c.getPoint(cX, cY);
	double ret = (((aX * bY) + (bX * cY) + (cX * aY)) - ((aX * cY) + (cX * bY) + (bX * aY)));
	if (ret < 0)
		ret *= -1;
	return (ret / 2);
}

bool Point::samPos(Point a, Point b, Point c, Point d)
{
	if (Point::pointOfLine(a, b, d))
		return (false);
	if (Point::pointOfLine(a, c, d))
		return (false);
	if (Point::pointOfLine(c, b, d))
		return (false);
	return (true);
}

bool Point::pointOfLine(Point a, Point b, Point d)
{
	float slope = (a.y.toFloat() - b.y.toFloat()) / (a.x.toFloat() - b.x.toFloat()); // 기울기
	float intercept = b.y.toFloat() - slope * b.y.toFloat(); // y절편
	if (d.y.toFloat() == slope * d.x.toFloat() + intercept) 
	{
		std::cout << "sam pos" << std::endl;
		return (false);
	}
	return (true);
}
