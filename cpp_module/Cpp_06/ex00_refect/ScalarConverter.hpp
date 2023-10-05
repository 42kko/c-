#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>

class ScalarConverter
{
    private:
        
    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &c);
        ScalarConverter& operator=(const ScalarConverter &c);
        static void convert(std::string s);
};