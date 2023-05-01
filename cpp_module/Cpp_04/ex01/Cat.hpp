#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *ideas;

public:
	Cat();
	Cat(const std::string &name);
	Cat(const Cat &c);
	Cat &operator=(const Cat &c);
	~Cat();
	std::string getType() const;
	void makeSound() const;
};

#endif