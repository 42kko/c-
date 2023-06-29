#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Bureaucrat kko("kko", 1);
        Intern someone;
        AForm *rrf;
        rrf = someone.makeForm("shrubbery creation", "kko");
        kko.signForm(*rrf);
        kko.executeForm(*rrf);
    }
    catch (std::exception &e)
    {
        std::cout << "err: " << e.what() << std::endl;
    }
    return (0);
}