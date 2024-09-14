#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string cible);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    bool execute(Bureaucrat const & executor) const ;
    private:
    std::string cible;
};

#endif