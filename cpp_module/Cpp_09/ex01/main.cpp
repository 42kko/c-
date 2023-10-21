#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    try
    {
        rpn c(av[1]);
    }
    catch (std::string &e)
    {
        std::cout << e << std::endl;
    }
}