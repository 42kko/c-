#include "Cat.hpp"

Cat::Cat() : Animal(), ptr(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const std::string name) : Animal(name), ptr(new Brain())
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &c) : Animal(c), ptr(NULL)
{
	std::cout << "Cat copy called" << std::endl;
	*this = c;
}

Cat& Cat::operator=(const Cat &c)
{
	std::cout << "Cat assignation called" << std::endl;
	this->_type = c._type;
	if (c.ptr)
		ptr = new Brain(*c.ptr);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->ptr;
}

std::string Cat::getType() const
{
	return(this->_type);
}

void Cat::makeSound() const
{
	std::cout << "meow meow~" << std::endl;
}