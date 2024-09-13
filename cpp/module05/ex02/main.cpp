#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <iostream>

int main()
{
try {
	Bureaucrat yes("YESSUR", 150);
    ShrubberyCreationForm garden("garden");
    yes.executeForm(garden);
    garden.beSigned(yes);
}
catch (std::exception & e)
{
	std::cout << e.what() << std::endl;
}
 try{
 	Bureaucrat yes("YESSUR", 100);
 	ShrubberyCreationForm garden("garden");
 	garden.beSigned(yes);
    	yes.executeForm(garden);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
try{
    Bureaucrat mr("mr", 1);
    PresidentialPardonForm pardonForm("target");
    pardonForm.beSigned(mr);
    mr.executeForm(pardonForm);
}
catch (std::exception & e)
{
	std::cout << e.what() << std::endl;
}

try {
    Bureaucrat mr("mr", 1);
    RobotomyRequestForm robotomyForm("target");
    robotomyForm.beSigned(mr);
    mr.executeForm(robotomyForm);
}
catch (std::exception & e)
{
	std::cout << e.what() << std::endl;
}

}