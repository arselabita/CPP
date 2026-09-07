#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("Default target")
{
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), _target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) : AForm(original), _target(original._target)
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
    if (this != &original)
    {
        AForm::operator=(original);
        this->_target = original._target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::cout << "* bzzzzz drilling noise *" << std::endl;
    if (rand() % 2)
        std::cerr << "Robotomy failed!!" << std::endl;
    else
        std::cout << _target << " has been robotimized." << std::endl;
}