#include "Character.hpp"

Character::Character()
{
	_name = "NULL";
	_inventory = new MateriaSource;
}

Character::Character(const std::string &name)
{
	_name = name;
	std::cout << "character name: " << name << std::endl;
	_inventory = new MateriaSource;
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
	_inventory->equip(m);
}

void Character::unequip(int idx)
{
	_inventory->MateriaSource::unequip(idx);
}

void Character::use(int idx, ICharacter &target)
{
	_inventory->use(idx, target);
}