#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
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
    MutantStack();
    // ~MutantStack();
    // MutantStack(const MutantStack &c);
    // MutantStack& operator=(const MutantStack &c);
    // template <typename T>
    std::vector<T>::iter& begin();
    // template <typename T>
    typename std::vector<T>::iter& end();
};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
typename std::vector<T>::iterator& begin()
{
    return c.begin();
}

template <typename T>
typename std::vector<T>::iterator& end()
{
    return c.end();
}

#endif

