#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        PresidentialPardonForm work("you");
        Bureaucrat kko("kko", 1);
        work.beSigned(kko);
        work.execute(kko);
    }
    catch (std::exception &e)
    {
        std::cout << "err: " << e.what() << std::endl;
    }

    try
    {
        ShrubberyCreationForm work("you");
        Bureaucrat kko("kko", 1);
        work.beSigned(kko);
        work.execute(kko);
    }
    catch (std::exception &e)
    {
        std::cout << "err: " << e.what() << std::endl;
    }

    try
    {
        RobotomyRequestForm work("you");
        Bureaucrat kko("kko", 1);
        work.beSigned(kko);
        work.execute(kko);
    }
    catch (std::exception &e)
    {
        std::cout << "err: " << e.what() << std::endl;
    }
    return (0);
}