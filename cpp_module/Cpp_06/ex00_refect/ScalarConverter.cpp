#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &c)
{
    *this = c;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &c)
{
    if (this == &c)
    {
        return (*this);
    }
    return (*this);
}

void ScalarConverter::convert(std::string s)
{
    
}