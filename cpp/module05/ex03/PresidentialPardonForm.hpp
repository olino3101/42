#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string cible);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    void do_exec() const override;
    private:
    std::string cible;
};

#endif