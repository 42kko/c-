#include "Contact.hpp"

Contact::Contact()
{
	empty = true;
}

void Contact::setFirst()
{
	std::cout << "Please enter your first name: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	if (tmp.empty())
	{
		std::cout << "It's impossible to leave a blank" << std::endl;
		Contact::setFirst();
	}
	else
		this->firstName = tmp;
}

void Contact::setLast()
{
	std::cout << "Please enter a last name: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	if (tmp.empty())
	{
		std::cout << "It's impossible to leave a blank" << std::endl;
		Contact::setLast();
	}
	else
		this->lastName = tmp;
}

void Contact::setNick()
{
	std::cout << "Please enter a nick name: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	if (tmp.empty())
	{
		std::cout << "It's impossible to leave a blank" << std::endl;
		Contact::setNick();
	}
	else
		this->nickName = tmp;
}

void Contact::setNumber()
{
	std::cout << "Please enter a phone number: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	std::size_t found = tmp.find("0123456789");
	if (found != std::string::npos)
		{
			std::cout << "only number" << std::endl;
			Contact::setNumber();
		}
	if (tmp.empty())
	{
		std::cout << "It's impossible to leave a blank" << std::endl;
		Contact::setNumber();
	}
	else
		this->phoneNumber = tmp;
}

void Contact::setSecret()
{
	std::cout << "Please enter a darkest secret: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	this->secret = tmp;
	empty = false;
}

std::string Contact::getFirst()
{
	return (this->firstName);
}

std::string Contact::getLast()
{
	return (this->lastName);
}

std::string Contact::getNick()
{
	return (this->nickName);
}

std::string Contact::getNumber()
{
	return (this->phoneNumber);
}

std::string Contact::getSecret()
{
	return (this->secret);
}

bool Contact::getEmpty()
{
	return (this->empty);
}