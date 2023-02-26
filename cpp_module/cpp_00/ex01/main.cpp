#include "PhoneBook.hpp"

int	main()
{
	PhoneBook book;
	Contact tmp;
	while (1)
	{
		std::string command;
		std::cout << "ADD SEARCH EXIT" << std::endl;
		std::cin >> command;
		if (command == "ADD")
		{
			book.makeContact();
		}
		else if (command == "SEARCH")
		{
			book.show();
		}
		else if (command == "EXIT")
			return (0);
		else if (command == "\0")
			return (0);
		else
			std::cout << "fail" << std::endl;
	}
	return (0);
	// contact[0].setFirst(command);
	// book.setContact(contact[0]);
	// book.show();
}

/*
과제가 80년대 전화번호부 만들기

클레스가 2개
1개 - 내용물
1개 - 책


ADD search exit



ADD 8개 

book -> contact 변수
book 객체 contact객체에 접근할수잇나??
*/