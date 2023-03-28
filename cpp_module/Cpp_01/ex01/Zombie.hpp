#ifndef Zombie_H
#define Zombie_H
#include <iostream>
#include <string>


class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void announce();
		void setName(std::string name);
};

Zombie *newZombie(std::string name);
Zombie* zombieHorde(int N,std::string name);

#endif