#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string &name);
		Cat(const Cat &c);
		Cat& operator=(const Cat &c);
		~Cat();
		std::string getType() const;
		void makeSound() const;
};

#endif