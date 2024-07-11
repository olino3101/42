#ifndef FORM_HPP
#define  FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
    const std::string name;
    bool IsSigned = false;
    const int gradeMin;
    const int gradeExec;
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

    AForm();
    AForm(std::string InitName, int InitGradeMin, int InitGradeExec);
    AForm(const Form& other);
    virtual ~AForm();
    bool getIsSigned() const ;
    int getGradeMin() const ;
    int getGradeExec() const ;
    std::string getName() const;
    virtual Form& operator=(const AForm& other);
    void beSigned(Bureaucrat & bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const AForm & rhs);
#endif