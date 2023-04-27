#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const std::string name) : Animal(name)
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &c) : Animal(c)
{
	std::cout << "Dog copy called" << std::endl;
	*this = c;
}

Dog& Dog::operator=(const Dog &c)
{
	std::cout << "Dog assignation called" << std::endl;
	this->_type = c._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getType() const
{
	return(this->_type);
}

void Dog::makeSound() const
{
	std::cout << "Wal Wal!" << std::endl;
}