#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
    delete rrf;

    AForm* rrf2;
    rrf = someRandomIntern.makeForm("Form that does not exist", "Bender");
    delete rrf2;
}