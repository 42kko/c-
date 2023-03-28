#ifndef HUMANA_H
#define HUMANA_H
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &club;
	public:
		HumanA(std::string name, Weapon& type);
		void attack();
};

#endif