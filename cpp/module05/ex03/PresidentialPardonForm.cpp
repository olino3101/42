#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string initCible)
    : AForm("Presidential Pardon Form", 5, 25), cible(initCible) {
}

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", 5, 25), cible("default"){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : 
    AForm("Robotomy Request Form", 5, 25), cible(other.cible) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other)
    {
        this->cible = other.cible;
        return *this;
    }
    return *this;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw NotSignedExeptionError();
    else if (executor.GetGrade() > getGradeExec())
        throw TooLowExeptionError();
    else
    {
        std::cout << cible << " have been forgive by Zaphod Beeblebrox" << std::endl;
        return true;
    }
    return false;
}
