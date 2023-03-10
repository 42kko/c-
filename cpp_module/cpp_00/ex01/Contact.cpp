#include "Contact.hpp"

void Contact::setFirst()
{
	std::cout << "Please enter your first name: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	this->firstName = tmp;
}

void Contact::setLast()
{
	std::cout << "Please enter a last name: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	this->lastName = tmp;
}

void Contact::setNick()
{
	std::cout << "Please enter a nick name: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	this->nickName = tmp;
}

void Contact::setNumber()
{
	std::cout << "Please enter a phone number: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	this->phoneNumber = tmp;
}

void Contact::setSecret()
{
	std::cout << "Please enter a darkest secret: ";
	std::string tmp;
	if (!std::getline(std::cin, tmp))
		exit (0);
	this->secret = tmp;
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
