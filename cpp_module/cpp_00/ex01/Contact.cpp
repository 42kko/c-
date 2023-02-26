#include "Contact.hpp"

void Contact::setFirst(std::istream &first)
{
	first >> this->firstname;
}

void Contact::setLast(std::istream &first)
{
	first >> this->lastname;
}

void Contact::setNick(std::istream &first)
{
	first >> this->nickname;
}

void Contact::setNumber(std::istream &first)
{
	first >> this->phoneNumber;
}

void Contact::setSecret(std::istream &first)
{
	first >> this->secret;
}

std::string Contact::getFirst()
{
	return (this->firstname);
}