#include "Zombie.hpp"

int main()
{
	Zombie roo("roo");
	roo.announce();

	Zombie *kko = new Zombie("kko");
	kko->announce();
	Zombie *foo = newZombie("foo");
	foo->announce();
	delete kko;
	delete foo;

	randomChump("hoo");
	return(0);
}