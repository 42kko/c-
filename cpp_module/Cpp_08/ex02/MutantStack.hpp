#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include <stack>

template <typename type, typename container = std::vector<type>, typename size>
class MutantStack : public std::stack<type, container, size>
{

};

#endif