#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string secret;
	public:
		void setFirst(std::string first);
		// void setLast(std::string last);
		// void setNick(std::string nick);
		// void setNumber(std::string number);
		// void setSecret(std::string secret);
		std::string getFirst();
};

#endif