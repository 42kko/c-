#include "Form.hpp"

Form::Form()
: _name(""), _signGrade(0), _executeGrade(0)
{
}

Form::Form(std::string name, int signGrade, int executeGrade) throw(GradeTooHighException, GradeTooLowException) 
: _name(name), _sign(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw GradeTooHighException();
    else if (_signGrade > 150 || _executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &c)
: _name(c._name), _sign(false), _signGrade(c._signGrade), _executeGrade(c._executeGrade)
{
}

Form& Form::operator=(const Form &c)
{
    if (this == &c)
        return (*this);
    _sign = c._sign;
    return (*this);
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
    return (_name);
}

const bool& Form::getSign() const
{
    return (_sign);
}

const int& Form::getSignGrade() const
{
    return (_signGrade);
}

const int& Form::getExecuteGrade() const
{
    return (_executeGrade);
}


void Form::beSigned(const Bureaucrat &c) throw (GradeTooLowException, AlreadySigned)
{
    if (_sign)
        throw AlreadySigned();
    if (c.getGrade() > _signGrade) 
        throw GradeTooLowException();
    _sign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form: grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form: grade too low");
}

const char *Form::AlreadySigned::what() const throw()
{
    return ("Form: already signed");
}

std::ostream& operator<<(std::ostream &o, const Form &c)
{
    o << c.getName() << ", form sign grade " << c.getSignGrade() << " , execute grade " << c.getExecuteGrade() << std::endl;
    return (o);
}