#include "ScalarConverter.hpp"
#include <stdexcept>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Please provide the arguments accurately" << std::endl;
        return (1);
    }
    std::string str(av[1]);
    if (str.find_first_not_of("123456789") != std::string::npos || str.compare("nan") != 0 || str.compare("inf") != 0 | str.compare("-inf"))
    if (((str.find_first_not_of("1234567890") != std::string::npos && str.find_first_not_of("1234567890") == str.size()) || str.back() != 'f') && str.compare("nan") != 0 && str.compare("inf") != 0 && str.compare("+inf") != 0 && str.compare("-inf") != 0 && str.compare("inff") != 0 && str.compare("+inff") != 0 && str.compare("-inff") != 0)
    {
        std::cerr << "err" << std::endl;
        return (1);
    }
    
    ScalarConverter::convert(av[1]);
    return (0);
}