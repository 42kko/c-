#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _sign;
        const int _signGrade;
        const int _executeGrade;
        Form();
    public:
        Form(std::string name, int signGrade, int executeGrade) throw(GradeTooHighException, GradeTooLowException);
        Form(const Form &c);
        Form& operator=(const Form &c);
        virtual ~Form();
        const std::string& getName() const;
        const bool& getSign() const;
        void beSigned(const Bureaucrat &c) throw(GradeTooLowException, AlreadySigned);
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class AlreadySigned : public std::exception
        {
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream &o,const Form &c);

#endif