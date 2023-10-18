// #include "MutantStack.hpp"
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::vector<T> >
{
    public:
        typedef typename std::vector<T>::iterator iterator;
        iterator begin();
        iterator end();
        void pop();
};

template <typename T>
typename std::vector<T>::iterator MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename std::vector<T>::iterator MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
void MutantStack<T>::pop()
{
    this->c.pop_back();
}


int main()
{
    // MutantStack<int> a;
    // a.push(4);
    // a.push(3);
    // MutantStack<int>::iter iter = a.begin();
    // std::cout << *a.begin() << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    // std::stack<int> s(mstack);
    return 0;
}

