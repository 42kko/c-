#include "Contact.hpp"

void Contact::setFirst(std::string first)
{
	this->firstname = first;
}

std::string Contact::getFirst(void)
{
	return (this->firstname);
}