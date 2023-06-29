#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &c)
{
    *this = c;
}

Intern& Intern::operator=(const Intern &c)
{
    if(this == &c)
        return (*this);
    return (*this);
}

AForm* Intern::makeForm(std::string form, std::string target)
{
    std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 3;
    for (i = 0; i < 3; i++)
    {
        if (arr[i] == form)
            break;
    }
    AForm *ret;
    switch (i)
    {
    case 0:
        ret = new ShrubberyCreationForm(target);
        break;
    case 1:
        ret = new RobotomyRequestForm(target);
        break;
    case 2:
        ret = new PresidentialPardonForm(target);
        break;
    default:
        throw NotFoundForm();
        break;
    }
    std::cout << "Intern creates " << arr[i] << " form"<< std::endl;
    return (ret);
}

const char* Intern::NotFoundForm::what() const throw()
{
    return ("Form not found");
}