#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &original);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
    virtual ~PresidentialPardonForm();

    void execute(Bureaucrat const &executor) const;

private:
    std::string _target;
};