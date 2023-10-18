#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>
#include "Span.hpp"

int main()
{
    {
        Span sp = Span(5);
        try
        {
            sp.addNumber(6.1);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(21);
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        }
        catch(std::string &e)
        {
            std::cout << e << std::endl;
        }
    }
    {
        // Span sp1 = Span(10000);
        // sp1.fillUp();
        // std::cout << sp1.shortestSpan() << std::endl;
        // std::cout << sp1.longestSpan() << std::endl;
    }
    return 0;
}