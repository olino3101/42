#ifndef AFORM_HPP
#define  AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class AForm
{
    private:
    const std::string name;
    const int gradeMin;
    const int gradeExec;
    bool IsSigned;
    protected:
        virtual void do_exec() const = 0;
    public:

    class NotSignedExeptionError : public std::exception
    {
        public:
            virtual const char* what() const throw () {
                return "Form::NotSignedExeptionError";
            }
    };

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
    AForm(const AForm& other);
    bool execute(Bureaucrat const & executor) const;
    virtual ~AForm();
    bool getIsSigned() const ;
    int getGradeMin() const ;
    int getGradeExec() const ;
    std::string getName() const;
    virtual AForm& operator=(const AForm& other);
    void beSigned(Bureaucrat & bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const AForm & rhs);
#endif