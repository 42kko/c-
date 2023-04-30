#include "Ice.hpp"

Ice::Ice() : AMateria()
{

}

Ice::Ice(const std::string &c) : AMateria(c)
{

}

Ice::Ice(const Ice &c) : AMateria(c)
{
	*this = c;
}

Ice& Ice::operator=(const Ice &c)
{
	this->_type = c._type;
	return (*this);
}

Ice::~Ice()
{

}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}