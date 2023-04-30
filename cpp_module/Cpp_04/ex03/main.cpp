// #include "AMateria.hpp"
// #include "ICharacter.hpp"
// #include "Character.hpp"
// #include "IMateriaSource.hpp"
// #include "MateriaSource.hpp"
// #include "Ice.hpp"
// #include "Cure.hpp"
// #include <iostream>
// #include <string>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"


int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());

}

