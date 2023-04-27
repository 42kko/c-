#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string name) : _type(name)
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &c)
{
	std::cout << "WrongAnimal copy called" << std::endl;
	*this = c;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &c)
{
	std::cout << "WrongAnimal assignation called" << std::endl;
	this->_type = c._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal Sound]" << std::endl;
}
