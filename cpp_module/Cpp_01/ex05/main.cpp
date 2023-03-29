#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	if (ac == 1)
	{
		std::cout << "Put in the level" << std::endl;
	}
	for(int i = 1; i < ac; i++)
	{
		harl.complain(av[i]);
	}
	return (0);
}