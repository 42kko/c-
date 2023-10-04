#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &c);
        RobotomyRequestForm& operator =(const RobotomyRequestForm &c);
        ~RobotomyRequestForm();
        virtual void execute() const;
};

#endif
