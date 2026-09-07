#include "Intern.hpp"

Intern::Intern()
{
}
Intern::Intern(const Intern &original)
{
    (void)original;
}
Intern &Intern::operator=(const Intern &original)
{
    if (this != &original)
    {
    }
    return *this;
}

Intern::~Intern()
{
    
}

AForm *Intern::makeForm(const std::string &nameOfForm, const std::string &targetOfForm)
{
    int index = -1;
    std::string arr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (nameOfForm == arr[i])
        {
            index = i;
            break;
        }
    }
    switch (index)
    {
    case 0:
        std::cout << "Intern creates: " << nameOfForm << std::endl;
        return new ShrubberyCreationForm(targetOfForm);
        break;
    case 1:
        std::cout << "Intern creates: " << nameOfForm << std::endl;
        return new RobotomyRequestForm(targetOfForm);
        break;
    case 2:
        std::cout << "Intern creates: " << nameOfForm << std::endl;
        return new PresidentialPardonForm(targetOfForm);
        break;
    default:
        std::cout << "Error: Intern cannot be created '" << nameOfForm << "' because it is unrecognised!" << std::endl;
        return NULL;
    }
}