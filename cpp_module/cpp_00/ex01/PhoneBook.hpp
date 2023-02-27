#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact book[8];
	public:
		void show();
		void setBook(Contact contact);
};

#endif