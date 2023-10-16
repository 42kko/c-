#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>

template <typename T>
class Array
{
    private:
        T *_array;
        size_t _size;
    public:
        Array();
        Array(unsigned int a);
        ~Array();
        Array(const Array &c);
        Array& operator=(const Array &c);
        T& operator[](size_t n);
        size_t size() const;
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const Array<T> c);


#include "Array.tpp"
#endif
