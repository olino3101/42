#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
int main()
{
	try {
		Intern someRandomIntern;
    	AForm* rrf;
    	rrf = someRandomIntern.makeForm("sdfsd", "Bender");
    	delete rrf;
	}
    
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try {
		Intern someRandomIntern;
		AForm* rrf2;
    	rrf2 = someRandomIntern.makeForm("Form that does not exist", "sdf");
    	delete rrf2;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}