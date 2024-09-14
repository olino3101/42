#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat  & rhs) {
os << rhs.GetName() << ", bureaucrat grade " << rhs.GetGrade() << std::endl;
return os;
}

std::string Bureaucrat::GetName() const {
    return this->name;
}

int  Bureaucrat::GetGrade() const {
    return this->grade;
}

void Bureaucrat::UpGrade()
{
        if (grade == 1)
            throw TooHighExeptionError();
    this->grade--;
}

void Bureaucrat::DownGrade()
{
        if (grade == 150)
            throw TooLowExeptionError();
    this->grade++;
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
}

Bureaucrat::Bureaucrat(std::string InitName, int InitGrade) : name(InitName), grade(InitGrade) {
   
        if (InitGrade < 1)
            throw TooHighExeptionError();
        if (InitGrade > 150)
            throw TooLowExeptionError();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    this->grade = other.grade;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

void Bureaucrat::signForm(const AForm & form) {
    if (form.getIsSigned())
        std::cout << name << " signed " << form.getName() << std::endl;
    else
        std::cout << name << " couldn't sign " << form.getName() << " because"
        << "grade too low" <<std::endl;
}

void Bureaucrat::executeForm(AForm const & form) {
    if (form.execute(*this))
        std::cout << name << " Executed " << form.getName() << std::endl;
    else
        std::cout << "could not execute form" << std::endl;
}
