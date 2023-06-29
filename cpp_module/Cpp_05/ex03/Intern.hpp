#ifndef INTERN_HPP
#define INTERN_HPP
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:

    public:
    Intern();
    ~Intern();
    Intern(const Intern &c);
    Intern& operator=(const Intern &c);
    AForm* makeForm(std::string form, std::string target);
    class NotFoundForm : public std::exception
    {
        virtual const char* what() const throw();
    };

};

#endif