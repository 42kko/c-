#include <algorithm>
#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &t, const int &i)
{
    typename T::iterator iter = std::find(t.begin(), t.end(), i);
    if (iter == t.end())
        throw std::string ("not found");
    return iter;
}

#endif;