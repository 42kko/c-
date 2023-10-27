#include "PmergeMe.hpp"


int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cout << "need more input" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe sort(ac, av);
        sort.setDeque();
        sort.setVector();
        sort.print();
    }
    catch(std::string &e)
    {
        std::cout << e << std::endl;
    }
}