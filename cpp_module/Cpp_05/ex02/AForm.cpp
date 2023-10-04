#include "AForm.hpp"

AForm::AForm()
: _name(""), _signGrade(0), _executeGrade(0)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade, std::string target) throw(GradeTooHighException, GradeTooLowException) 
: _name(name), _sign(false), _signGrade(signGrade), _executeGrade(executeGrade), _target(target)
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw GradeTooHighException();
    else if (_signGrade > 150 || _executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &c)
: _name(c._name), _sign(false), _signGrade(c._signGrade), _executeGrade(c._executeGrade), _target(c._target)
{
}

AForm& AForm::operator=(const AForm &c)
{
    if (this == &c)
        return (*this);
    _sign = c._sign;
    return (*this);
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
    return (_name);
}

const bool& AForm::getSign() const
{
    return (_sign);
}

const int& AForm::getSignGrade() const
{
    return (_signGrade);
}

const int& AForm::getExecuteGrade() const
{
    return (_executeGrade);
}

void AForm::beSigned(const Bureaucrat &c) throw (GradeTooLowException, AlreadySigned)
{
    if (_sign)
        throw AlreadySigned();
    if (c.getGrade() > _signGrade) 
        throw GradeTooLowException();
    _sign = true;
}

void AForm::beExecute(const Bureaucrat &c) const throw (GradeTooLowException, NotSinged)
{
    if (!_sign)
        throw NotSinged();
    if (c.getGrade() > _executeGrade)
        throw GradeTooLowException();
    this->execute();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm: grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("AForm: grade too low");
}

const char *AForm::AlreadySigned::what() const throw()
{
    return ("AForm: already signed");
}

const char *AForm::NotSinged::what() const throw()
{
    return ("AForm: not singed");
}

std::ostream& operator<<(std::ostream &o, const AForm &c)
{
    o << c.getName() << ", Aform grade " << std::endl;
    return (o);
}