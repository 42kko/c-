#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat aaa("aaa", -1);
        std::cout << "here" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Err: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat aaa("aaa", 151);
        std::cout << "here" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Err: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat kko("kko", 2);
        std::cout << kko << std::endl;
        kko.incrementGrade();
        std::cout << kko << std::endl;
        kko.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Err: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat kko("kko", 149);
        std::cout << kko << std::endl;
        kko.decrementGrade();
        std::cout << kko << std::endl;
        kko.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Err: " << e.what() << std::endl;
    }

    return (0);
}