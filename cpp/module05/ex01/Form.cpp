#include "Form.hpp"

Form::Form(std::string InitName, int InitGradeMin, int InitGradeExec) 
    : name(InitName), gradeMin(InitGradeMin), gradeExec(InitGradeExec), IsSigned(false) {
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

Form::Form() : name("default"), gradeMin(150), gradeExec(150), IsSigned(false) {
    std::cout << "default constructor called" << std::endl;
}

Form::Form(const Form& other) : 
    name(other.name), gradeMin(other.gradeMin), gradeExec(other.gradeExec), IsSigned(other.IsSigned) {
    std::cout << "copy constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "destructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    if (this != &other)
    {
        IsSigned = other.IsSigned;
    }
    return *this;
}

bool Form::getIsSigned() const {
    return this->IsSigned;
}
int Form::getGradeMin() const {
    return this->gradeMin;
}
int Form::getGradeExec() const {
    return this->gradeExec;
}
std::string Form::getName() const {
    return this->name;
}

std::ostream& operator<<(std::ostream& os, const Form  & rhs) {
    std::string sign = ", it is not sign";
    if (rhs.getIsSigned())
        sign = ", it is sign";
    os << rhs.getName() << ": grade minimum to sign " << rhs.getGradeMin() 
    << ", grade required to execute " << rhs.getGradeExec() << sign <<std::endl;
    return os;
}

void Form::beSigned(Bureaucrat & bureaucrat) {
    try {
        if (bureaucrat.GetGrade() <= gradeMin)
        {
            IsSigned = true;
            bureaucrat.signForm(*this);
        }
            
        else
            throw TooLowExeptionError();
    }
    catch (TooLowExeptionError& e){
        std::cout << e.what() << std::endl;
    }
    
}