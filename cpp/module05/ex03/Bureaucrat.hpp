#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
    public:

    class TooLowExeptionError : public std::exception
    {
        public:
            virtual const char* what() const throw () {
                return "Bureaucrat::GradeTooLowException";
            }
    };

    class TooHighExeptionError : public std::exception
    {
        public:
            virtual const char* what() const throw () {
                return "Bureaucrat::GradeTooHighException";
            }
    };

    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat& other);
    std::string GetName() const;
    int GetGrade() const;
    void UpGrade();
    void DownGrade();
    void signForm(const AForm & form);
    void executeForm(AForm const & form);

    private:
    const std::string name;
    int grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat & rhs);

#endif