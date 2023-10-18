// #include "MutantStack.hpp"
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <stack>

int main()
{
    std::stack<int,std::vector<int> > a;
    a.push(188);
    a.push(18);
    std::vector<int>::iterator iter = a.c.begin();
    std::cout << *iter << std::endl;
}

