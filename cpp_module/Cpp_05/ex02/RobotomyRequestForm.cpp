#include "RobotomyRequestForm.hpp"

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

void RobotomyRequestForm::execute() const
{
    std::cout << " drilling noises " << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << this->getName() <<" has been robotomized" <<std::endl;
    else
        std::cout << this->getName() <<" filed robotomized" << std::endl;
}