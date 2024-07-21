#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string initCible)
    : AForm("Presidential Pardon Form", 5, 25), cible(initCible) {
    std::cout << "default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", 5, 25), cible("default"){
    std::cout << "default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : 
    AForm("Robotomy Request Form", 5, 25), cible(other.cible) {
    std::cout << "copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
    {
        this->cible = other.cible;
        return *this;
    }
    return *this;
}
void PresidentialPardonForm::do_exec() const{
    std::cout << cible << " have been forgive by Zaphod Beeblebrox" << std::endl;
}