#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Err: Please provide the arguments accurately" << std::endl;
        return (1);
    }
    try
    {
        ScalarConverter::convert(std::string(av[1]));
    }
    catch(const char *s)
    {
        std::cerr << s << '\n';
    }
    
    return (0);
}
