#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ] " << std::endl\
	<< "I love having extra bacon for my 7XL-double-" 
	<< "cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ] " << std::endl\
	<<"I cannot believe adding extra bacon costs more money. You didn’t put eno"
	<< "ugh bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ] " << std::endl\
	<< "I think I deserve to have some extra bacon for free. I’ve been coming for ye"
	<< "ars whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ] " << std::endl\
	<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*f[4])() = {&Harl::debug, &Harl::info, \
	&Harl::warning, &Harl::error};
	std::string str[4] = {"debug", "info", "warning", "error"};
	std::string str1[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int pos = -1;
	for (int i = 0; i < 4; i++)
	{
		if(level == str[i] || level == str1[i])
		{
			pos = i;
		}
	}
	switch (pos)
	{
	case 0 :
		(this->*f[0])();
	case 1 :
		(this->*f[1])();
	case 2 :
		(this->*f[2])();
	case 3 :
		(this->*f[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}