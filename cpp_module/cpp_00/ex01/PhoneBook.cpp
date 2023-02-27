#include "PhoneBook.hpp"

void PhoneBook::show()
{
	std::cout << this->book[0].getFirst() << std::endl;
}

void PhoneBook::setBook(Contact contact)
{
	this->book[0] = contact;
}