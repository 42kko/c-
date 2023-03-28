#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *club;
	public:
		HumanB(std::string name);
		void setWeapon(Weapon &type);
		void attack();
};

#endif