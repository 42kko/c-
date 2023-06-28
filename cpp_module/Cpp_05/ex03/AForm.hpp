#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    protected:
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
        class NotSinged : public std::exception
        {
            virtual const char* what() const throw();
        };
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream &o,const AForm &c);

#endif