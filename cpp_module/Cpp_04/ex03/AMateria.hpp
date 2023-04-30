#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"
// #include "MateriaSource.hpp"

// class Character;
class ICharacter;
// class MateriaSource;
// class IMateriaSource;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(const std::string &c);
		AMateria(const AMateria &c);
		AMateria& operator=(const AMateria &c);
		virtual ~AMateria();
		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif