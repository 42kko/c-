#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *meta = new Animal();
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();
	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl;
	WrongAnimal *wrong_animal = new WrongAnimal();
	WrongAnimal *wrong_cat = new WrongCat();
	wrong_animal->makeSound();
	wrong_cat->makeSound();
	delete wrong_animal;
	delete wrong_cat;
	return (0);
}
