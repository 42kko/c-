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
		bool operator>(const Fixed& c) const;
		bool operator<(const Fixed& c) const;
		bool operator>=(const Fixed& c) const;
		bool operator<=(const Fixed& c) const;
		bool operator==(const Fixed& c) const;
		bool operator!=(const Fixed& c) const;
		Fixed operator+(const Fixed& c) const;
		Fixed operator-(const Fixed& c) const;
		Fixed operator*(const Fixed& c) const;
		Fixed operator/(const Fixed& c) const;
		Fixed & operator++();
		Fixed operator++(int x);
		Fixed & operator--();
		Fixed operator--(int x);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		static Fixed& min(Fixed& a, Fixed & b );
		static Fixed& max(Fixed& a, Fixed & b );
		static const Fixed& min(const Fixed & a, const Fixed & b );
		static const Fixed& max(const Fixed & a, const Fixed & b );
};

std::ostream & operator<<(std::ostream& os, const Fixed& c);

#endif