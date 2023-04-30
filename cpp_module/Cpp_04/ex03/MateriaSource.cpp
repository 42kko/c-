#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	 _inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &c)
{
	*this = c;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &c)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = c._inventory[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
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
		return ;
	}
	_inventory[idx] = m;
}

AMateria* MateriaSource::creatMateria(const std::string &type)
{
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[idx])
			return (0);
		if (_inventory[idx]->getType() == type)
			return (_inventory[idx]->clone());
		idx++;
	}
	return (0);
}

void MateriaSource::unequip(const int &idx)
{
	if (!_inventory[idx])
	{
		std::cout << "Inventory is empty" << std::endl;
		return ;
	}
	else
		_inventory[idx] = 0;
}