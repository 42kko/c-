#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(i << 8);
}

Fixed::Fixed(float i)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(i * 256));
}

Fixed::Fixed(const Fixed& c)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = c;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& c)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPoint = c.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const
{
	return(this->fixedPoint);
}

void Fixed::setRawBits(const int raw)
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

std::ostream & operator<<(std::ostream& os, const Fixed& c)
{
	os << c.toFloat();
	return (os);
}
