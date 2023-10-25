#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &c)
{
    *this = c;
}

template <typename T>
 MutantStack<T>& MutantStack<T>::operator=(const MutantStack &c)
{
    if (this == &c)
        return *this;
    this->c = c.c;
    return *this;
}

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
