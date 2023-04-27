#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const std::string name);
		Animal(const Animal &c);
		Animal& operator=(const Animal &c);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif