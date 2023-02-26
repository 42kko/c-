#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact book[8];
		int lowest;
	public:
		PhoneBook()
		{
			lowest = 0;
		}
		void show();
		void makeContact();
		void firstname(std::string first);
};

#endif