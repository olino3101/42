#include "Intern.hpp"

AForm *Intern::ShrubberyCreation(std::string cible)
{
    return new ShrubberyCreationForm(cible);
}

AForm *Intern::PresidentialPardon(std::string cible)
{
    return new RobotomyRequestForm(cible);
}

AForm *Intern::RobotomyRequest(std::string cible) 
{
    return new PresidentialPardonForm(cible);
}

AForm* Intern::makeForm(std::string name, std::string cible) {
    if (name.empty() || cible.empty())
    {
        std::cout << "error empty string" << std::endl;
        return NULL; 
    }
    //AForm *form;
    int i = 0;
    AForm* (Intern::*Ptrs[])(std::string cible) = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};
    std::string forms[] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
    while (i != 3 && forms[i].compare(name))
        i++;
    if (i == 3)
        std::cout << "Wrong form name" << std::endl;
    else
        return (this->*Ptrs[i])(cible);
    return NULL;
}

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern::~Intern() {
    std::cout << "destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}