#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include <string>

class AMateria
{
	protected:
		std::string name;
	public:
		AMateria();
		AMateria(const std::string &type);
		const std::string& getType() const;

};

#endif