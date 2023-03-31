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
		// Point(const Point& c);
		// ~Point();
		// Point& operator=(const Point& c);
};

#endifw