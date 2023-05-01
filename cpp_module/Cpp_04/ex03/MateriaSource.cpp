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
		std::cout << "Source is full" << std::endl;
		delete m;
		return ;
	}
	_inventory[idx] = m;
	std::cout << "Source: " << _inventory[idx]->getType() << " learn" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string &type)
{
	int idx = 0;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[idx])
		{
			std::cout << "Source is empty" << std::endl;
			return (0);
		}
		if (_inventory[idx]->getType() == type)
		{
			return (_inventory[idx]->clone());
		}
		idx++;
	}
	std::cout << "There is no matching source" << std::endl;
	return (0);
}

void MateriaSource::equip(AMateria *m)
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
	std::cout << "equip: " << "[" << idx << "] " << _inventory[idx]->getType() << std::endl;
}

void MateriaSource::unequip(const int &idx)
{
	if (!_inventory[idx])
	{
		std::cout << "can't be unequip: not equipped" << std::endl;
		return ;
	}
	else
	{
		std::cout << "unequip: " << "[" << idx << "] " << _inventory[idx]->getType() << std::endl;
		_inventory[idx] = 0;
	}
}

void MateriaSource::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Wrong idx" << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << "empty idx" << std::endl;
		return ;
	}
	_inventory[idx]->use(target);
}

