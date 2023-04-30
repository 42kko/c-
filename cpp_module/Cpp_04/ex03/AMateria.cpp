#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "NULL";
}

AMateria::AMateria(const std::string &type)
{
	_type = type;
}

AMateria::AMateria(const AMateria &c)
{
	*this = c;
}

AMateria& AMateria::operator=(const AMateria &c)
{
	_type = c._type;
	return (*this);
}

AMateria::~AMateria()
{

}

const std::string& AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{ 
	std::cout << "* usd Materia " << target.getName() << " *" << std::endl;
}