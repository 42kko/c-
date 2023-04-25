#ifndef FIXED_H
#define FIXED_H
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixedPoint;
		static const int bit = 8;
	public:
		Fixed();
		Fixed(int i);
		Fixed(float i);
		Fixed(const Fixed& c);
		~Fixed();
		Fixed& operator=(const Fixed& c);
		int getRawBits() const;
		void setRawBits(const int raw);
		float toFloat() const;
		int toInt() const;
};

std::ostream & operator<<(std::ostream& os, const Fixed& c);

#endif