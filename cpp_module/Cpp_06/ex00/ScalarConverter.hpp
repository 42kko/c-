#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string> 
#include <cctype>
#include <iomanip>

class ScalarConverter
{
    private:
        static char _c;
        static void print(long long i);
        static void print(float f);
        static void print(double d);
        static void print(std::string s);
    public:
        ScalarConverter();
        virtual ~ScalarConverter();
        ScalarConverter(const ScalarConverter &c);
        ScalarConverter& operator=(const ScalarConverter &c);
        static void convert(std::string s);
};

#endif