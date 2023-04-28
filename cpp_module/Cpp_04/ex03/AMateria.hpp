#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include <string>

class AMateria
{
	protected:
		std::string _name;
	public:
		AMateria();
		AMateria(const std::string &c);
		AMateria& operator=(const AMateria &c);
		~AMateria();
		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif