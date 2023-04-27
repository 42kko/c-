#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *ptr;
	public:
		Dog();
		Dog(const std::string name);
		Dog(const Dog &c);
		Dog& operator=(const Dog &c);
		~Dog();
		std::string getType() const;
		void makeSound() const;
};

#endif