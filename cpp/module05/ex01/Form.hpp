#ifndef FORM_HPP
#define  FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
    const std::string name;
    const int gradeMin;
    const int gradeExec;
    bool IsSigned;
    public:

    class TooLowExeptionError : public std::exception
    {
        public:
            virtual const char* what() const throw () {
                return "Form::GradeTooLowException";
            }
    };

    class TooHighExeptionError : public std::exception
    {
        public:
            virtual const char* what() const throw () {
                return "Form::GradeTooHighException";
            }
    };

    Form();
    Form(std::string InitName, int InitGradeMin, int InitGradeExec);
    Form(const Form& other);
    ~Form();
    bool getIsSigned() const ;
    int getGradeMin() const ;
    int getGradeExec() const ;
    std::string getName() const;
    Form& operator=(const Form& other);
    void beSigned(Bureaucrat & bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form & rhs);
#endif