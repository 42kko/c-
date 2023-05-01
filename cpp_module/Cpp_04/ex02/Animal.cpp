#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &name) : _type(name)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &c)
{
	std::cout << "Animal copy called" << std::endl;
	*this = c;
}

Animal &Animal::operator=(const Animal &c)
{
	std::cout << "Animal assignation called" << std::endl;
	this->_type = c._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "[Animal Sound]" << std::endl;
}
