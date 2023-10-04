#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat kko("kko", 2);
        std::cout << kko << std::endl;
        Form work1("work1", -1, 15);
        kko.signForm(work1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Err: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat kko("kko", 149);
        std::cout << kko << std::endl;
        Form work1("work1", 1, 151);
        kko.signForm(work1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Err: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat kko("kko", 10);
        std::cout << kko << std::endl;
        Form work1("work1", 30, 15);
        //work1.beSigned(kko);
        kko.signForm(work1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Err: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat kko("kko", 31);
        std::cout << kko << std::endl;
        Form work1("work1", 30, 15);
        kko.signForm(work1);
    }
    catch (std::exception &e)
    {
        std::cerr << "Err: " << e.what() << std::endl;
    }
    return (0);
}