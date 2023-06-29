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

void ScalarConverter::convert(std::string str)
{
    bool point = false;
    bool flo = false;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '.')
        {
            point = true;
        }
        if (str[i] == 'f' || point)
        {
            flo = true;
            break;
        }
    }
    char *endptr;
    if (flo)
        print(std::strtof(str.c_str(), &endptr));
    else if (point || str.find("nan") != std::string::npos)
        print(std::strtod(str.c_str(), &endptr));
    else
        print(std::strtol(str.c_str(), &endptr, 10));
}

void ScalarConverter::print(long x)
{
    std::stringstream ss;
    std::string result;
    if (x < 0 || x > 127)
        result = "It's not ascii";
    else
    {
        ss << static_cast<char>(x);
        result = ss.str();
    }
    std::cout << "char: " << (x == 0 ? "Non displayable" : result) << std::endl;
    if (((x == LONG_MAX || x == LONG_MIN) && errno == ERANGE) || (x < -2147483648 || x > 2147483647))
    std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << x << std::endl;
    std::cout << "float: " << static_cast<float>(x) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(x) << std::endl;
}

void ScalarConverter::print(float x)
{
    std::stringstream ss;
    std::string result;
    if (x < 0 || x > 127)
        result = "It's not ascii";
    else
    {
        ss << static_cast<char>(x);
        result = ss.str();
    }
    std::cout << "char: " << (x == 0 ? "Non displayable" : result) << std::endl;
    if ((((x) == LONG_MAX || (x) == LONG_MIN) && errno == ERANGE) || (static_cast<int>(x) <= -2147483648 || static_cast<int>(x) > 2147483647))
    std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(x) << std::endl;
    std::cout << "float: " << x << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(x) << std::endl;
}

void ScalarConverter::print(double x)
{
    std::stringstream ss;
    std::string result;
    if (x < 0 || x > 127)
        result = "It's not ascii";
    else
    {
        ss << static_cast<char>(x);
        result = ss.str();
    }
    std::cout << "char: " << (x == 0 ? "Non displayable" : result) << std::endl;
    if ((((x) == LONG_MAX || (x) == LONG_MIN) && errno == ERANGE) || (static_cast<int>(x) <= -2147483648 || static_cast<int>(x) > 2147483647))
    std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(x) << std::endl;
    std::cout << "float: " << static_cast<float>(x) << "f" << std::endl;
    std::cout << "double: " << x << std::endl;
}