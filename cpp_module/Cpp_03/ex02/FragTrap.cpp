#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap constructors" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "FragTrap constructors" << std::endl;
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& c)
{
	std::cout << "FragTrap copy constructors" << std::endl;
	this->name = c.name;
	this->hitPoints = c.hitPoints;
	this->energyPoints = c.energyPoints;
	this->attackDamage = c.attackDamage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& c)
{
	std::cout << "FragTrap operator=" << std::endl;
	this->name = c.name;
	this->hitPoints = c.hitPoints;
	this->energyPoints = c.energyPoints;
	this->attackDamage = c.attackDamage;
	return (*this);
}

void FragTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << this->name << " inability to act" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << this->name << " take " << amount << " damage" << std::endl;
	this->hitPoints = this->hitPoints > amount ? this->hitPoints - amount : 0;
	if (this->hitPoints == 0)
		std::cout << this->name << "is dead" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0 || this->hitPoints == 0)
	{
		std::cout << this->name << " inability to act" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " repaired " << amount << " points"<<std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " high fives guys" << std::endl;
}