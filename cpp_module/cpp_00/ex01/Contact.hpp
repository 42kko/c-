#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string secret;
	public:
		void setFirst();
		void setLast();
		void setNick();
		void setNumber();
		void setSecret();
		std::string getFirst();
		std::string getLast();
		std::string getNick();
		std::string getNumber();
		std::string getSecret();
};

#endif