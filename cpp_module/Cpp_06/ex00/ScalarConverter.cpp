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
    bool flo, duo, pseudo = false;

    if (s.find_first_not_of("0123456789.f+-") == std::string::npos || s.compare("nan") == 0 || s.compare("nanf") == 0 || s.compare("+inf") == 0 || s.compare("-inf") == 0 || s.compare("-inff") == 0 || s.compare("+inff") == 0)
    {
        if (s.find('f') != std::string::npos)
        {
            if (s.rfind('f') != s.size() - 1 || (s.find('f') != s.rfind('f') && s.find('f') != s.rfind('f') - 1))
                throw "Err: Invalid input";
            flo = true;
        }
        if (s.find('.') != std::string::npos)
        {
            if (s.find('.') == s.size() - 1 || s[s.find('.') + 1] == 'f' || s.find_first_of('.') == 0 || s.rfind('.') != s.find('.'))
                throw "Err: Invalid input";
            duo = true;
        }
        if (s.find_first_not_of("0123456789.+-f") != std::string::npos || s.find("nan") != std::string::npos)
            pseudo = true;
        if (s.find_first_not_of("-+") != std::string::npos || (s.find("-+") == s.rfind("-+") && s.find("-+") != std::string::npos))
        {
            if (s.find_last_of("-+") != 0 && s.find_last_of("+-") != std::string::npos)
                throw "Err1: Invalid input";
        }
    }
    else
        throw "Err: Invalid input";
    if (pseudo)
        print(s);
    else if (flo)
        print(std::strtof(s.c_str(), NULL));
    else if (duo)
        print(std::strtod(s.c_str(), NULL));
    else if (!pseudo)
        print(std::atoll(s.c_str()));
}

void ScalarConverter::print(long long i)
{
    if (i < 1 || i > 150)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << '\'' << static_cast<char>(i) << '\'' << std::endl;
    if (i > 2147483647 || i < -2147483648)
        std::cout << "int : Non displayable" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::print(float f)
{
    if (f < 1 || f > 150)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << '\'' << static_cast<char>(f) << '\'' << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << (f) << 'f' << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::print(double d)
{
    if (d < 1 || d > 150)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << '\'' << static_cast<char>(d) << '\'' << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(d) << 'f' << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::print(std::string s)
{
    std::cout << "char: impossible" << std::endl;;
    std::cout << "int: impossible" << std::endl;
    std::string arr[3] = {"nan", "+", "-"};
    int i = 3;
    for (i = 0; i < 3; i++)
    {
        if (s.find(arr[i]) != std::string::npos)
            break;

    }
    switch (i)
    {
    case 0:
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        break;
    case 1:
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        break;
    case 2:
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        break;
    default:
        break;
    }
}