#ifndef CURE_HPP
#define CURE_HPP
#include "main.cpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &c);
		Cure& operator=(const Cure &c);
		~Cure();
};

#endif