#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	// ScavTrap a;
	// ScavTrap b("Morgan");
	// ScavTrap c(b);
	DiamondTrap d("kko");
	// ClapTrap *e;
	// ScavTrap *e;
	// e = &d;
	// std::cout << d.getName() << std::endl;
	d.monitor();
	d.attack("target");
	// std::cout << e->getName() << std::endl;
	// std::cout << c.getName() << std::endl;
}