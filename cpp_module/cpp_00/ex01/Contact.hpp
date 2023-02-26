#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phoneNumber;
		std::string secret;
	public:
		void setFirst(std::istream &first);
		void setLast(std::istream &last);
		void setNick(std::istream &nick);
		void setNumber(std::istream &number);
		void setSecret(std::istream &secret);
		std::string getFirst();
};

#endif