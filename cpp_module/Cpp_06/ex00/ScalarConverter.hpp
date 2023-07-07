#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
    private:
        static void print(long x);
        static void print(float x);
        static void print(double x);
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &c);
        ScalarConverter& operator=(const ScalarConverter &c);
        static void convert(std::string s);
};

#endif