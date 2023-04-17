#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap constructors" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& newName) : ClapTrap(newName)
{
	std::cout << "ScavTrap constructors" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& c) : ClapTrap(c)
{
	std::cout << "ScavTrap copy constructors" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& c)
{
	std::cout << "ScavTrap operator=" << std::endl;
	this->name = c.name;
	this->hitPoints = c.hitPoints;
	this->energyPoints = c.energyPoints;
	this->attackDamage = c.attackDamage;
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << this->name << " inability to act" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << this->name << " take " << amount << " damage" << std::endl;
	this->hitPoints = this->hitPoints > amount ? this->hitPoints - amount : 0;
	if (this->hitPoints == 0)
		std::cout << this->name << "is dead" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << this->name << " inability to act" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " repaired " << amount << " points"<<std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}

void guardGate()
{
	std::cout << "ScavTrap has enterred in Gate keeper mode" << std::endl;
}