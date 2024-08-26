#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string initCible)
    : AForm("formulaire de creation darbustes", 137, 145), cible(initCible) {
    std::cout << "default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("formulaire de creation darbustes", 137, 145), cible("default"){
    std::cout << "default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : 
    AForm("formulaire de creation darbustes", 137, 145), cible(other.cible) {
    std::cout << "copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
    {
        this->cible = other.cible;
        return *this;
    }
    return *this;
}
void ShrubberyCreationForm::do_exec() const{
    std::ofstream outFile(this->getName().c_str());
    if (!outFile) {
        std::cout << "error opening file" << std::endl;
        return ;
    }
    outFile << "   /\\\n"
            << "  /  \\\n"
            << " /____\\\n"
            << "   ||\n"
            << "   ||\n";
    outFile.close();
}
