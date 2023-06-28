#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &c);
        PresidentialPardonForm& operator =(const PresidentialPardonForm &c);
        ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const & executor) const;
};

#endif
