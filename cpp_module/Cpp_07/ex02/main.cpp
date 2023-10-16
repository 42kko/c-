#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	{
		Array<int> a;
		Array<int> b(4);
		Array<int> c(2);
		c[0] = 10;
		// std::cout << "11111111" << std::endl;
		std::cout << "a:" << a << std::endl;
		std::cout << "b:" << b << std::endl;
		std::cout << "c:" <<c << std::endl;
		b = c;
		b[1] = 5;
		std::cout << "after b:" << b << std::endl;
		try 
		{
			b[6] = 0;
		} 
		catch(std::exception e) 
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Array<std::string> a;
		Array<std::string> b(4);
		Array<std::string> c(2);
		Array<std::string> d(a);

		c[0] = "hello";
		std::cout << "a:" <<a << std::endl;
		std::cout << "b:" <<b << std::endl;
		std::cout << "c:" <<c << std::endl;
		b = c;
		try
		{
			b[1] = "world";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try 
		{
			b[2] = "cpp07";
		} 
		catch(std::exception e) 
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << "after b:" << b << std::endl;
	}
}