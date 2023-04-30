#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include <string>
#include "AMateria.hpp"

// class AMateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria* createMateria(std::string const &type) = 0;
		virtual void unequip(const int &idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

#endif