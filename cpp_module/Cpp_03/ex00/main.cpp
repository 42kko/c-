#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("kko");
	ClapTrap b("woo");
	ClapTrap c(a);
	ClapTrap d;
	d = a;

	a.attack("woo");
	a.takeDamage(9);
	a.beRepaired(10);
}