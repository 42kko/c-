#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	lowest = 0;
}
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
		else if (found != std::string::npos || !(std::atoi(tmp.c_str()) >= 1 && std::atoi(tmp.c_str()) <= 8))
			std::cout << "Wrong index" << std::endl;
		else if (std::atoi(tmp.c_str()) >= 1 && std::atoi(tmp.c_str()) <= 8)
		{
			if (!book[std::atoi(tmp.c_str()) - 1].getEmpty())
			{
				std::cout << "first name: ";
				std::cout << book[std::atoi(tmp.c_str()) - 1].getFirst() << std::endl;
				std::cout << "last name: ";
				std::cout << book[std::atoi(tmp.c_str()) - 1].getLast() << std::endl;
				std::cout << "nick name: ";
				std::cout << book[std::atoi(tmp.c_str()) - 1].getNick() << std::endl;
				std::cout << "phone number: ";
				std::cout << book[std::atoi(tmp.c_str()) - 1].getNumber() << std::endl;
				std::cout << "darkest secret: ";
				std::cout << book[std::atoi(tmp.c_str()) - 1].getSecret() << std::endl;
				return ;
			}
			else
				std::cout << "index empty" << std::endl;
		}
		std::cout << "Enter the index you want to see, if you want to go back type in the 'b': ";
	}
	exit (0);
}

void PhoneBook::makeContact()
{
	book[lowest].setFirst();
	book[lowest].setLast();
	book[lowest].setNick();
	book[lowest].setNumber();
	book[lowest].setSecret();
	this->lowest++;
	if (this->lowest == 8)
		this->lowest = 0;
}