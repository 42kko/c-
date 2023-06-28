#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) throw(GradeTooHighException, GradeTooLowException) 
: _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &c)
: _name(c._name), _grade(c._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &c)
{
    if (this == &c)
        return (*this);
    _grade = c._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName() const
{
    return (this->_name);
}

const int& Bureaucrat::getGrade() const
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
    return ("Bureaucrat: grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat: grade too low");
}

void Bureaucrat::signForm(AForm &c) const
{
    try
    {
        c.beSigned(*this);
        std::cout << _name << " signed " << c.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn’t sign " << c.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm &c)
{
    try
    {
        c.execute(*this);
        std::cout << _name << " executed " << c.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn’t executed " << c.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &c)
{
    o << c.getName() << ", bureaucrat grade " << c.getGrade();
    return (o);
}