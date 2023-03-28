#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact book[8];
		int lowest;
	public:
		PhoneBook();
		void show();
		void makeContact();
		void showDetail();
};

#endif