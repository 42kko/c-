#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &c)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = c;
}

Brain& Brain::operator=(const Brain &c)
{
	std::cout << "Brain assignation called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = c._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Dog destructor called" << std::endl;
}
