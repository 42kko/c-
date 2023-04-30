#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &c);
		MateriaSource& operator=(const MateriaSource &c);
		virtual ~MateriaSource();
		void learnMateria(AMateria *m);
		AMateria* createMateria(const std::string &type);
		void unequip(const int &idx);
		void use(int idx, ICharacter &target);
};

#endif