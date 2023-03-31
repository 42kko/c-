#include "Point.hpp"

Point::Point() : x(), y()
{
	std::cout << "default constructor" << std::endl;
}

Point::Point(float x, float y) : x(x), y(y)
{
	std::cout << "default constructor put two para" << std::endl;
	std::cout << x << y << std::endl;
}