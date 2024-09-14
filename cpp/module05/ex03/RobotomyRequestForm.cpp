#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string initCible)
    : AForm("Robotomy Request Form", 45, 72), cible(initCible) {
}

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 45, 72), cible("default"){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : 
    AForm("Robotomy Request Form", 45, 72), cible(other.cible) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
    {
        this->cible = other.cible;
        return *this;
    }
    return *this;
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw NotSignedExeptionError();
    else if (executor.GetGrade() > getGradeExec())
        throw TooLowExeptionError();
    else
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        int rn = std::rand() % 100 + 1;
        std::cout << cible << "mzzzz mzzzz (bruit de perceuse)" << std::endl;
        if (rn > 50)
            std::cout << "operation fails" << std::endl;
        else
            std::cout << "operation success" << std::endl;
        return true;
    }
    return false;
}
