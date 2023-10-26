#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: check Argument" << std::endl;
		return 1;
	}
	try
	{
		bitcoinExchange bit(av[1]);
		bit.exchange(av[1]);
	}
	catch(std::string &e)
	{
		std::cout << e <<std::endl;
	}
	return 0;
}