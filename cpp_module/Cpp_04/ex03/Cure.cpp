#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const std::string &c) : AMateria(c)
{

}

Cure::Cure(const Cure &c) : AMateria(c)
{
	*this = c;
}

Cure& Cure::operator=(const Cure &c)
{
	this->_type = c._type;
	return (*this);
}

Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}