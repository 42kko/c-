#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed
{
	private:
		int fixedPoint;
		static const int bit = 8;
	public:
		Fixed();
		Fixed(const Fixed& c);
		~Fixed();z
		Fixed& operator=(const Fixed& c);
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif