#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>

int main()
{
// test shruberry
    Bureaucrat yes("YESSUR", 150);
    ShrubberyCreationForm garden("garden");
    yes.executeForm(garden);
    garden.beSigned(yes);
    // Bureaucrat yes("YESSUR", 100);
    // ShrubberyCreationForm garden("garden");
    // garden.beSigned(yes);
    // yes.executeForm(garden);

//test presidential form
    //Bureaucrat mr("mr", 1);
    //PresidentialPardonForm pardonForm("target");
    //pardonForm.beSigned(mr);
    //mr.executeForm(pardonForm);

//test Robotomy
    //Bureaucrat mr("mr", 1);
    //RobotomyRequestForm robotomyForm("target");
    //robotomyForm.beSigned(mr);
    //mr.executeForm(robotomyForm);
}