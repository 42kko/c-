#include "Character.hpp"

Character::Character()
{
	_name = "NULL";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name)
{
	_name = name;
	std::cout << "character name: " << name << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character &Character::operator=(const Character &c)
{
	_name = c._name;
	_inventory = c._inventory;
	return (*this);
}

Character::~Character()
{
	delete _inventory;
}

const std::string &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			idx = i;
			break;
		}
		idx++;
	}
	if (idx > 3)
	{
		std::cout << "Inventory is full" << std::endl;
		return;
	}
	_inventory[idx] = m;
	std::cout << "equip: "
			  << "[" << idx << "] " << _inventory[idx]->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (!_inventory[idx])
	{
		std::cout << "can't be unequip: not equipped" << std::endl;
		return;
	}
	else
	{
		std::cout << "unequip: "
				  << "[" << idx << "] " << _inventory[idx]->getType() << std::endl;
		_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter &target)
{
}