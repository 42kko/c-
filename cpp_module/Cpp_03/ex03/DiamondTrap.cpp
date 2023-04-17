#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap constructor" << std::endl;
}

// DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
// {
// 	std::cout << "DiamondTrap constructor called" << std::endl;
// 	this->_name = name;
// }
