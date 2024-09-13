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
            throw  TooHighExeptionError();
		this->grade--;
}

void Bureaucrat::DownGrade()
{
        if (grade == 150)
            throw TooLowExeptionError();
		this->grade++;
		return ;
}

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
    std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string InitName, int InitGrade) : name(InitName), grade(InitGrade) {
        if (InitGrade < 1)
            throw TooHighExeptionError();
        if (InitGrade > 150)
            throw TooLowExeptionError();
		std::cout << "value constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << "copy constructor called" << std::endl;
    this->grade = other.grade;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}