#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include <string>
#include "AMateria.hpp"

// class AMateria;

class IMateriaSource
{
	public:
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria* creatMateria(std::string const &type) = 0;
};

#endif