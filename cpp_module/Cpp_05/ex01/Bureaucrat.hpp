#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    Bureaucrat();
public:
    Bureaucrat(const std::string &name, const int &grade) throw(GradeTooHighException, GradeTooLowException);
    Bureaucrat(const Bureaucrat &c);
    Bureaucrat& operator=(const Bureaucrat &c);
    virtual ~Bureaucrat();
    const std::string& getName() const;
    const int& getGrade() const;
    void incrementGrade() throw(GradeTooHighException);
    void decrementGrade() throw(GradeTooLowException);
    class GradeTooHighException : public std::exception
    {
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        virtual const char* what() const throw();
    };
    void signForm(Form &c) const;
};

std::ostream& operator<<(std::ostream &o,const Bureaucrat &c);

#endif