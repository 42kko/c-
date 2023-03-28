#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		std::string& getType();
		void setType(std::string);
};

#endif