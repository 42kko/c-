#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const std::string &c);
		Cure(const Cure &c);
		Cure& operator=(const Cure &c);
		virtual ~Cure();
		virtual AMateria* clone() const;
		virtual void use(ICharacter &target);
};

#endif