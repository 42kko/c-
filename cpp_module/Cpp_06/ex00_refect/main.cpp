// #include "ScalarConverter.hpp"
#include <iostream>
#include <string> 
#include <cctype>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Err: Please provide the arguments accurately" << std::endl;
        return (1);
    }
    std::string s(av[1]);
    if ((s.find_first_not_of("0123456789.f") == std::string::npos && s.find('.') == s.rfind('.') && s.find('f') == s.rfind('f')) || s.compare("nan") == 0 || s.compare("nanf") == 0 || s.compare("+inf") == 0 || s.compare("-inf") == 0 || s.compare("-inff") == 0 || s.compare("+inff") == 0)
    {
        if (s.find('f') != std::string::npos)
        {
            if (s.find('f') != s.size() - 1)
            {
                std::cout << "err" << std::endl;
                return (1);
            }
        }
        else if (s.find('.') != std::string::npos)
        {
            if (s.find('.') == s.size() - 1 || s[s.find('.') + 1] == 'f')
            {
                std::cout << "err" << std::endl;
                return (1);
            }
        }

        std::cout << "hi"   <<  std::endl <<    s[s.find('.') + 1] << std::endl;
    }
}
