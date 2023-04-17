#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructors" << std::endl;
}

ClapTrap::ClapTrap(const std::string& newName)
: name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructors" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
: name(c.name), hitPoints(c.hitPoints), energyPoints(c.energyPoints), attackDamage(c.attackDamage)
{
	std::cout << "ClapTrap copy constructors" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	std::cout << "ClapTrap operator=" << std::endl;
	this->name = c.name;
	this->hitPoints = c.hitPoints;
	this->energyPoints = c.energyPoints;
	this->attackDamage = c.attackDamage;
	return(*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << this->name << " inability to act" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take " << amount << " damage" << std::endl;
	this->hitPoints = this->hitPoints > amount ? this->hitPoints - amount : 0;
	if (this->hitPoints == 0)
		std::cout << this->name << "is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << this->name << " inability to act" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " repaired " << amount << " points"<<std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}

void ClapTrap::setName(std::string newName)
{
	this->name = newName;
}

void ClapTrap::setHitPoints(unsigned int amount)
{
	this->hitPoints = amount;
}

void ClapTrap::setEnergyPoints(unsigned int amount)
{
	this->energyPoints = amount;
}

void ClapTrap::setAttackDamage(unsigned int amount)
{
	this->attackDamage = amount;
}

std::string ClapTrap::getName()
{
	return (this->name);
}

unsigned int ClapTrap::getHitPoints()
{
	return (this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints()
{
	return (this->energyPoints);
}

unsigned int ClapTrap::getAttackDamage()
{
	return (this->attackDamage);
}
