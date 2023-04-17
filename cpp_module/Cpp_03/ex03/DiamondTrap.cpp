#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap constructor" << std::endl;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const std::string& newName) : ClapTrap(newName + "_clap_name"), FragTrap(newName), ScavTrap(newName)
{
	std::cout << "DiamondTrap constructor" << std::endl;
	this->_name = newName;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& c) : ClapTrap(c), FragTrap(c), ScavTrap(c)
{
	std::cout << "DiamondTrap copy constructor" << std::endl;
	this->_name = c._name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& c)
{
	std::cout << "DiamondTrap operator=" << std::endl;
	this->_name = c._name;
	this->hitPoints = c.hitPoints;
	this->energyPoints = c.energyPoints;
	this->attackDamage = c.attackDamage;
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap whoAmI: " << this->name << std::endl;
	std::cout << "DiamondTrap whoAmI: " << this->_name << std::endl;
}

std::string DiamondTrap::getName()
{
	return (this->_name);
}

void DiamondTrap::monitor(void)
{
	std::cout << "_name: " << this->_name << " \\ name: " << this->name << " \\ hitPoints: " << this->hitPoints \
	<< " \\ energyPoints: " << this->energyPoints << " \\ attackDamage: " << this->attackDamage << std::endl;
}