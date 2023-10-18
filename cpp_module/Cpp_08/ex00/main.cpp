#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(12);
    vec.push_back(13);
    try
    {
        std::vector<int>::iterator iter = easyfind(vec, 13);
        std::cout << *iter << std::endl;
    }
    catch(std::string &e)
    {
        std::cout << e << std::endl;
    }
    return (0);
}