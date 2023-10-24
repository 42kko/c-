#include "PmergeMe.hpp"

void print(int ac, char **av, PmergeMe &vec, PmergeMe &deq)
{
    std::ostringstream buffer; 
    buffer << "Before: ";
    av++;
    while(*av)
    {
        buffer << *av << " ";
        av++;
        std::string str = buffer.str();
        if (str.size() > 25)
        {
            buffer << "[...]";    
            break;
        }
    }
    buffer << "\n";
    buffer << "After:  ";
    std::vector<unsigned long> v = vec.getVec();
    for(std::vector<unsigned long>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        buffer << *iter << " ";
        std::string str = buffer.str();
        if (str.size() > 55)
        {
            buffer << "[...]";    
            break;
        }
    }
    buffer << std::endl;
    std::cout << buffer.str();
    std::cout << "Time to process a range of" << ac - 1 << "elements with std::vector : " << vec.getTimeV() << " us" << std::endl;
    std::cout << "Time to process a range of" << ac - 1 << "elements with std::deque : " << deq.getTimeD() << " us" << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "need more input" << std::endl;
        return 1;
    }
    else if (ac == 2)
    {
        std::cout << "hi\n";
        return 0;
    }
    try
    {
        PmergeMe vec(ac, av);
        PmergeMe deq(ac, av, 1);
        print(ac, av, vec, deq);
    }
    catch(std::string &e)
    {
        std::cout << e << std::endl;
    }
}