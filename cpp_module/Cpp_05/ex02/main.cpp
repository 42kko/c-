#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        //sign 25, exec 5
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
        //sign 145, exec 137
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
        //sign 72, exec 45
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