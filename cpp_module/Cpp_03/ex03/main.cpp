#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	ScavTrap a;
	ScavTrap b("Morgan");
	ScavTrap c(b);

	std::cout << c.getName() << std::endl;
}