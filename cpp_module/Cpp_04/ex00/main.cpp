#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	const Animal* wrong_animal = new Animal();
// 	const Animal* wrong_cat = new Cat();

// 	std::cout << std::endl;
// 	wrong_cat->makeSound();
// 	wrong_animal->makeSound();
// 	return 0;
// }


int main( void )
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "Dog->getType [" << dog->getType() << "] " << std::endl;
	std::cout << "Cat->getType [" << cat->getType() << "] " << std::endl;
	cat->makeSound(); //will output the cat sound! (not the Animal)
	dog->makeSound(); //will output the dog sound! (not the Animal)
	animal->makeSound(); //will output the animal sound

	std::cout << std::endl;
	const Animal* wrong_animal = new Animal();
	const Animal* wrong_cat = new Cat();

	std::cout << std::endl;
	wrong_cat->makeSound();
	wrong_animal->makeSound();

	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;
	delete wrong_cat;
	delete wrong_animal;
}
