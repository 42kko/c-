#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _sign;
        const int _signGrade;
        const int _executeGrade;
        const std::string _target;
        AForm();
    public:
        AForm(std::string name, int signGrade, int executeGrade, std::string target) throw(GradeTooHighException, GradeTooLowException);
        AForm(const AForm &c);
        AForm& operator=(const AForm &c);
        virtual ~AForm();
        const std::string& getName() const;
        const bool& getSign() const;
        const int& getSignGrade() const;
        const int& getExecuteGrade() const;
        void beSigned(const Bureaucrat &c) throw(GradeTooLowException, AlreadySigned);
        void beExecute(const Bureaucrat &c) const throw(GradeTooLowException, NotSinged);
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
        class NotSinged : public std::exception
        {
            virtual const char* what() const throw();
        };
        virtual void execute() const = 0;
};

std::ostream& operator<<(std::ostream &o,const AForm &c);

#endif