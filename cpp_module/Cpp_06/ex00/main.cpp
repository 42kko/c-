#include "ScalarConverter.hpp"
#include <stdexcept>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Err: Please provide the arguments accurately" << std::endl;
        return (1);
    }
    std::string str(av[1]);
    if (str.find_first_not_of("1234567890.f") != std::string::npos && str.compare("nan") != 0 && str.compare("inf") != 0 && str.compare("+inf") != 0 && str.compare("-inf") != 0 && str.compare("inff") != 0 && str.compare("+inff") != 0 && str.compare("-inff") != 0)
    {
        std::cerr << "Err: invalid argument" << std::endl;
        return (1);
    }
    if (str.find("f") != std::string::npos || str.find(".") != std::string::npos)
    {
        if ((str.back() != 'f' || str.find("f") != str.length() - 1) && str.find("f") != std::string::npos)
        {
                std::cerr << "Err: invalid argument" << std::endl;
                return (1);
        }
        if (str.find(".") != std::string::npos)
        {
            size_t idx = str.find(".");
            std::cout << idx << str.find_last_of(".") << std::endl;
            if (str.find_last_of(".") != idx || str.find_first_of("1234567890") == std::string::npos)
            {
                std::cerr << "Err: invalid argument" << std::endl;
                return (1);
            }
        }
    }
    ScalarConverter::convert(av[1]);
    return (0);
}