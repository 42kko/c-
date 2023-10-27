#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: check Argument" << std::endl;
        return 0;
    }
    try
    {
        rpn c;
        c.calculation(av[1]);
    }
    catch (std::string &e)
    {
        std::cout << e << std::endl;
    }
}