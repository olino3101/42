#include "AForm.hpp"

AForm::AForm(std::string InitName, int InitGradeMin, int InitGradeExec) 
    : name(InitName), gradeMin(InitGradeMin), gradeExec(InitGradeExec) {
    std::cout << "value constructor called" << std::endl;
    try {
        if (InitGradeMin < 1 || InitGradeExec < 1)
            throw TooHighExeptionError();
    }
    catch (TooHighExeptionError& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        if (InitGradeMin > 150 || InitGradeExec > 150)
            throw TooLowExeptionError();
    }
    catch (TooLowExeptionError& e) {
        std::cout << e.what() << std::endl;
    }
}

AForm::AForm() : gradeExec(150), gradeMin(150), name("default") {
    std::cout << "default constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : 
    name(other.name), IsSigned(other.IsSigned), gradeExec(other.gradeExec), gradeMin(other.gradeMin) {
    std::cout << "copy constructor called" << std::endl;
}
  
AForm::~AForm() {
    std::cout << "destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
    {
        IsSigned = other.IsSigned;
    }
    return *this;
}

bool AForm::getIsSigned() const {
    return this->IsSigned;
}
int AForm::getGradeMin() const {
    return this->gradeMin;
}
int AForm::getGradeExec() const {
    return this->gradeExec;
}
std::string AForm::getName() const {
    return this->name;
}

std::ostream& operator<<(std::ostream& os, const AForm  & rhs) {
    std::string sign = ", it is not sign";
    if (rhs.getIsSigned())
        sign = ", it is sign";
    os << rhs.getName() << ": grade minimum to sign " << rhs.getGradeMin() 
    << ", grade required to execute " << rhs.getGradeExec() << sign <<std::endl;
    return os;
}

void AForm::beSigned(Bureaucrat & bureaucrat) {
    try {
        if (bureaucrat.GetGrade() <= gradeMin)
        {
            IsSigned = true;
            bureaucrat.signAForm(*this);
        }
            
        else
            throw TooLowExeptionError();
    }
    catch (TooLowExeptionError& e){
        std::cout << e.what() << std::endl;
    }
    
}