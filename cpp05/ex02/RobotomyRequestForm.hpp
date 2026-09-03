#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &original);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
    virtual ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;

private:
    std::string _target;
};