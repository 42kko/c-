#include "PhoneBook.hpp"

int	main()
{
	std::string str;
	Contact contact;
	std::cin >> str;
	contact.setFirst(str);
	PhoneBook book;
	book.setBook(contact);
	book.show();
}