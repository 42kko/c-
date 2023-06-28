#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &c)
    : AForm(c)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &c)
{
    if (this == &c)
        return (*this);
    AForm::operator=(c);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->_sign == false)
        throw NotSinged();
    else if (this->_executeGrade < executor.getGrade())
        throw GradeTooLowException();
    std::cout << " drilling noises " << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << _target <<" has been robotomized" <<std::endl;
    else
        std::cout << _target <<" filed robotomized" << std::endl;
}