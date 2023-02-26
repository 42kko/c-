#include "PhoneBook.hpp"

// index, first name, last
// name and nickname.

void PhoneBook::show()
{
	std::cout << std::setw(10) << "Index" <<\
	"|" << "First Name" << "|" << " Last Name| Nick Name\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		if (this->book[i].getFirst().length() > 9)
		{
			char tmp[11];
			this->book[i].getFirst().copy(tmp, 9, 0);
			tmp[9] = '.';
			tmp[10] = 0;
			std::cout << tmp << "|" << std::endl;
		}
		// std::cout << std::setw(10) << book[i].getFirst() << "|";
		// std::cout << std::setw(10) << book[i].getFirst() << "|";
		// std::cout << std::setw(10) << book[i].getFirst() << std::endl;
	}
}

void PhoneBook::makeContact()
{
	Contact contact;

	std::cout << "first_name plz: ";
	contact.setFirst(std::cin);
	std::cout << "last_name plz: ";
	contact.setLast(std::cin);
	std::cout << "nick_name plz: ";
	contact.setNick(std::cin);
	std::cout << "phone_number plz: ";
	contact.setNumber(std::cin);
	std::cout << "darkest_secret plz: ";
	contact.setSecret(std::cin);
	this->book[this->lowest % 8] = contact;
	this->lowest++;
}
