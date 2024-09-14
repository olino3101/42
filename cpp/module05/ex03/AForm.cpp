#include "AForm.hpp"

AForm::AForm(std::string InitName, int InitGradeMin, int InitGradeExec) 
    : name(InitName), gradeMin(InitGradeMin), gradeExec(InitGradeExec), IsSigned(false) {
        if (InitGradeMin < 1 || InitGradeExec < 1)
            throw TooHighExeptionError();
        if (InitGradeMin > 150 || InitGradeExec > 150)
            throw TooLowExeptionError();
}

AForm::AForm() : name("default"), gradeMin(150), gradeExec(150), IsSigned(false) {
}

AForm::AForm(const AForm& other) : 
    name(other.name), gradeMin(other.gradeMin), gradeExec(other.gradeExec), IsSigned(other.IsSigned) {
}
  
AForm::~AForm() {
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
        if (bureaucrat.GetGrade() <= gradeMin)
        {
            IsSigned = true;
            bureaucrat.signForm(*this);
        }     
        else
            throw TooLowExeptionError();
}

