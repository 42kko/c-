#include "Character.hpp"

Character::Character()
{
	_name = "NULL";
	_inventory = new MateriaSource;
}

Character::Character(const std::string &name)
{
	_name = name;
	_inventory = new MateriaSource;
}

Character& Character::operator=(const Character &c)
{
	_name = c._name;
	_inventory = c._inventory;
	return (*this);
}

Character::~Character()
{
	delete _inventory;
}

const std::string& Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	_inventory->learnMateria(m);
}

void Character::unequip(int idx)
{
	_inventory->MateriaSource::unequip(idx);
}