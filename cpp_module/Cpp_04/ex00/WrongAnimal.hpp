#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(const std::string name);
	WrongAnimal(const WrongAnimal &c);
	WrongAnimal &operator=(const WrongAnimal &c);
	virtual ~WrongAnimal();
	std::string getType() const;
	void makeSound() const;
};

#endif