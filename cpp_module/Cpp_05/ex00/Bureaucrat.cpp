#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) throw(GradeTooHighException, GradeTooLowException) : 
_name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &c) : _name(c._name)
{
    *this = c;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &c)
{
    _grade = c._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade -= 1;
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &c)
{
    o << c.getName() << ", bureaucrat grade " << c.getGrade();
    return (o);
}