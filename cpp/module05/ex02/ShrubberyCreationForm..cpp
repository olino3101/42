#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string initCible)
    : gradeExec(137), gradeMin(147), name("formulaire de création d’arbustes"), cible(initCible) {
    std::cout << "default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm() 
    : gradeExec(137), gradeMin(147), name("formulaire de création d’arbustes"), cible("default"){
    std::cout << "default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : 
    name(other.name), IsSigned(other.IsSigned), gradeExec(other.gradeExec), gradeMin(other.gradeMin) {
    std::cout << "copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
    {
        return *this;
        //IsSigned = other.IsSigned;
    }
    return *this;
}
