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
        kko.signForm(work);
        kko.executeForm(work);
    }
    catch (std::exception &e)
    {
        std::cout << "err: " << e.what() << std::endl;
    }

    try
    {
        ShrubberyCreationForm work("you");
        Bureaucrat kko("kko", 1);
        kko.signForm(work);
        kko.executeForm(work);
    }
    catch (std::exception &e)
    {
        std::cout << "err: " << e.what() << std::endl;
    }

    try
    {
        RobotomyRequestForm work("you");
        Bureaucrat kko("kko", 1);
        kko.signForm(work);
        kko.executeForm(work);
    }
    catch (std::exception &e)
    {
        std::cout << "err: " << e.what() << std::endl;
    }
    return (0);
}