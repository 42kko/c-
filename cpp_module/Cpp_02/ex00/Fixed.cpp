#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
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
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixedPoint);
}

void Fixed::setRawBits(const int raw)
{
	this->fixedPoint = raw;
}