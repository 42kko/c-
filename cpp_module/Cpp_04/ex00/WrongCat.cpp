#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const std::string name) : WrongAnimal(name)
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &c) : WrongAnimal(c)
{
	std::cout << "WrongCat copy called" << std::endl;
	*this = c;
}

WrongCat& WrongCat::operator=(const WrongCat &c)
{
	std::cout << "WrongCat assignation called" << std::endl;
	this->_type = c._type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string WrongCat::getType() const
{
	return(this->_type);
}

void WrongCat::makeSound() const
{
	std::cout << "meow meow~" << std::endl;
}