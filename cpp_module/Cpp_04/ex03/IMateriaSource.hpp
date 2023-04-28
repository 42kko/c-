#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP
#include "main.cpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria* creatMateria(std::string const &type) = 0;
};

#endif