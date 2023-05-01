#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const std::string &c);
	Ice(const Ice &c);
	Ice &operator=(const Ice &c);
	virtual ~Ice();
	virtual AMateria *clone() const;
	virtual void use(ICharacter &target);
};

#endif