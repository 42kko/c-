#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(7, 0);
	Point c(0, 5);

	std::cout << Point::area(a, b, c) << std::endl;
	Point d(0, 4);
	Point e(3, 0);
	Point f(0, 0);
	if (bsp(a, b, c, d) == 1)
		std::cout << "in" <<std::endl;
	else
		std::cout << "no" << std::endl;
	if (bsp(a, b, c, e) == 1)
		std::cout << "in" <<std::endl;
	else
		std::cout << "no" << std::endl;
	if (bsp(a, b, c, f) == 1)
		std::cout << "in" <<std::endl;
	else
		std::cout << "no" << std::endl;
	return (0);
}