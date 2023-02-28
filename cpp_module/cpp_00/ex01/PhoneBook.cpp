#include "PhoneBook.hpp"

void PhoneBook::show()
{
	std::cout << "|" << std::setw(10) << "Index" <<\
	"|" << "First Name" << "|" << " Last Name| Nick Name|\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		if (this->book[i].getFirst().length() > 9)
		{
			char tmp[11];
			this->book[i].getFirst().copy(tmp, 9, 0);
			tmp[9] = '.';
			tmp[10] = 0;
			std::cout << tmp << "|";
		}
		else
			std::cout << std::setw(10) << book[i].getFirst() << "|";
		if (this->book[i].getLast().length() > 9)
		{
			char tmp[11];
			this->book[i].getLast().copy(tmp, 9, 0);
			tmp[9] = '.';
			tmp[10] = 0;
			std::cout << tmp << "|";
		}
		else
			std::cout << std::setw(10) << book[i].getLast() << "|";
		if (this->book[i].getNick().length() > 9)
		{
			char tmp[11];
			this->book[i].getNick().copy(tmp, 9, 0);
			tmp[9] = '.';
			tmp[10] = 0;
			std::cout << tmp << "|" << std::endl;
		}
		else
			std::cout << std::setw(10) << book[i].getNick() << "|" << std::endl;
	}
}

void PhoneBook::showDetail()
{
	std::string tmp;
	std::cout << "Enter the index you want to see, if you want to go back type in the 'b': ";
	while (std::getline(std::cin, tmp))
	{
		std::size_t found = tmp.find_first_not_of("0123456789");
		if (tmp == "b")
			return ;
		else if (tmp == "\0")
			{}
		else if (found != std::string::npos || !(std::stoi(tmp) >= 1 && std::stoi(tmp) <= 8))
			std::cout << "Wrong index" << std::endl;
		else if (std::stoi(tmp) >= 1 && std::stoi(tmp) <= 8)
		{
			std::cout << "first name: ";
			std::cout << book[std::stoi(tmp) - 1].getFirst() << std::endl;
			std::cout << "last name: ";
			std::cout << book[std::stoi(tmp) - 1].getLast() << std::endl;
			std::cout << "nick name: ";
			std::cout << book[std::stoi(tmp) - 1].getNick() << std::endl;
			std::cout << "phone number: ";
			std::cout << book[std::stoi(tmp) - 1].getNumber() << std::endl;
			std::cout << "darkest secret: ";
			std::cout << book[std::stoi(tmp) - 1].getSecret() << std::endl;
			return ;
		}
	std::cout << "Enter the index you want to see, if you want to go back type in the 'b': ";
	}
	exit (0);
}

void PhoneBook::makeContact()
{
	Contact contact; 
	contact.setFirst();
	contact.setLast();
	contact.setNick();
	contact.setNumber();
	contact.setSecret();
	this->book[this->lowest % 8] = contact;
	this->lowest++;
}
