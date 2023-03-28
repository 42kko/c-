#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& type) : club(type)
{
	this->name = name;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << this->club.getType() << std::endl;
}
