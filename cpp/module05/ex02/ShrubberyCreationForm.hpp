#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
    public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::String cible);
    ShrubberyCreationForm(const Form& other);
    ~ShrubberyCreationForm();
    Form& operator=(const ShrubberyCreationForm& other);
    private:
    std::string cible;
};

#endif