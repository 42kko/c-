#ifndef ICE_HPP
#define ICE_HPP
#include "main.cpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &c);
		Ice& operator=(const Ice &c);
		~Ice();
};

#endif