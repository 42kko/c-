#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	// Animal i;
	Animal *i = new Cat;
	i->makeSound();
}
