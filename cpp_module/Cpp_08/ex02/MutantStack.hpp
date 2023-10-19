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
    private:
    public:
        typedef typename std::vector<T>::iterator iterator;
        MutantStack& operator=(const MutantStack &c);
        MutantStack(const MutantStack &c);
        MutantStack();
        ~MutantStack();
        iterator begin();
        iterator end();
};
#include "MutantStack.tpp"

#endif