#include "PhoneBook.hpp"

int	main()
{
	PhoneBook book;
	Contact contact;
	std::string command;
	std::cin >> command;
	book.setBook(contact);
	book.show();
}
