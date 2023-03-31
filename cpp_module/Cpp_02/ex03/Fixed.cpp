#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedPoint = 0;
}

Fixed::Fixed(int i)
{
	this->setRawBits(i << 8);
}

Fixed::Fixed(float i)
{
	this->setRawBits((int)roundf(i * 256));
}

Fixed::Fixed(const Fixed& c)
{
	*this = c;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& c)
{
	this->fixedPoint = c.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& c) const
{
	if (this->getRawBits() > c.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed& c) const
{
	if (this->getRawBits() < c.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed& c) const
{
	if (this->getRawBits() >= c.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed& c) const
{
	if (this->getRawBits() <= c.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed& c) const
{
	if (this->getRawBits() == c.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=( Fixed const & c) const
{
	if (this->getRawBits() != c.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed& c) const
{
	Fixed tmp(this->toFloat() + c.toFloat());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed& c) const
{
	Fixed tmp(this->toFloat() - c.toFloat());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed& c) const
{
	Fixed tmp(this->toFloat() * c.toFloat());
	return (tmp);
}

Fixed Fixed::operator/(const Fixed& c) const
{
	Fixed tmp(this->toFloat() / c.toFloat());
	return (tmp);
}

Fixed& Fixed::operator++()
{
	this->fixedPoint += 1;
	return (*this);
}

Fixed Fixed::operator++(int x)
{
	(void)x;
	Fixed temp = *this;

	(this->fixedPoint) +=1 ;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->fixedPoint -= 1;
	return (*this);
}


Fixed Fixed::operator--(int x)
{
	(void)x;
	Fixed temp = *this;

	(this->fixedPoint) -=1 ;
	return (temp);
}

int Fixed::getRawBits() const
{
	return(this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / 256);
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> 8);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}
	
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}
	
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream & operator<<(std::ostream& os, const Fixed& c)
{
	os << c.toFloat();
	return (os);
}
