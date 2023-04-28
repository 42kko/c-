#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;

	Animal *animals[4] = { NULL };
	for(int i=0; i<4; i++) {
		if (i % 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
	}
	for(int i=0; i<4; i++) {
		animals[i]->makeSound();
	}


	i->makeSound();
}
