#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &c);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &c);
    ~ShrubberyCreationForm();
    virtual void execute(Bureaucrat const &executor) const;
};

#endif
