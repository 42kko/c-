#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("B");
	ClapTrap c(b);
	ClapTrap d;
	d = c;
}