#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        PmergeMe(ac, av);
    }
    catch(std::string &e)
    {
        std::cout << e << std::endl;
    }
}