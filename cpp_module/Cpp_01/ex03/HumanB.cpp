#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->club = 0;
}

void HumanB::attack()
{
	if (this->club == NULL)
		std::cout << name << " attacks with their bare hands" << std::endl;
	else
		std::cout << name << " attacks with their " << this->club->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
	this->club = &type;
}