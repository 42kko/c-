#include "PhoneBook.hpp"

int	main()
{
	PhoneBook book;
	Contact tmp;
	std::string command;
	std::cout << "Commands \"ADD SEARCH EXIT\": ";
	while (std::getline(std::cin, command))
	{
		if (command == "ADD")
		{
			book.makeContact();
		}
		else if (command == "SEARCH")
		{
			book.show();
			book.showDetail();
		}
		else if (command == "EXIT")
			return (0);
		else
			std::cout << "Invalid command!" << std::endl;
		std::cout << "Commands \"ADD SEARCH EXIT\": ";
	}
	return (0);
}
