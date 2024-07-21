#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(std::string initCible)
    : AForm("Robotomy Request Form", 45, 72), cible(initCible) {
    std::cout << "default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 45, 72), cible("default"){
    std::cout << "default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : 
    AForm("Robotomy Request Form", 45, 72), cible(other.cible) {
    std::cout << "copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
    {
        this->cible = other.cible;
        return *this;
    }
    return *this;
}
void RobotomyRequestForm::do_exec() const{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    int rn = dis(gen);
    std::cout << cible << "mzzzz mzzzz (bruit de perceuse)" << std::endl;
    if (rn > 50)
        std::cout << "operation fails" << std::endl;
    else
        std::cout << "operation success" << std::endl;
}