#ifndef POINT_H
#define POINT_H
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(float x, float y);
		Point(const Point& c);
		~Point();
		Point& operator=(Point& c);
		bool getPoint(float& x, float& y) const;
		static bool samPos(Point a, Point b, Point c, Point d);
		static double area(Point a, Point b, Point c);
		static bool pointOfLine(Point a, Point b, Point d);
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif