#ifndef INTERN_HPP
#define  INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    AForm *ShrubberyCreation(std::string cible);
    AForm *RobotomyRequest(std::string cible); 
    AForm *PresidentialPardon(std::string cible);
   
public:
    ~Intern();
     Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    AForm* makeForm(std::string name, std::string cible);
};

#endif