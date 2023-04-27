#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string name);
		WrongCat(const WrongCat &c);
		WrongCat& operator=(const WrongCat &c);
		~WrongCat();
		std::string getType() const;
		void makeSound() const;
};

#endif