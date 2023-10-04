#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &c);
        PresidentialPardonForm& operator =(const PresidentialPardonForm &c);
        ~PresidentialPardonForm();
        virtual void execute() const;
};

#endif
