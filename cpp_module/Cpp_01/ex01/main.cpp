#include "Zombie.hpp"

int main()
{
	int N = 3;
	Zombie *p = zombieHorde(N, "kko");
	for(int i = 0; i < N; i++)
		p[i].announce();
	delete [] p;
}