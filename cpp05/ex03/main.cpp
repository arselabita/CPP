#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    AForm *rrf = NULL;

    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "\nTesting: The intern. (robotomy request)" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        rrf = someRandomIntern.makeForm("robotomy request", "bender");
        if (rrf != NULL)
        {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
            rrf = NULL;
        }
    }
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "\nTesting: The intern. (shrubbery creation)" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        rrf = someRandomIntern.makeForm("shrubbery creation", "hera");
        if (rrf != NULL)
        {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
            rrf = NULL;
        }
    }
    std::cout << BOLD << BLUE << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << BLUE << "\nTesting: The intern. (presidential pardon)" << RESET << std::endl;
    std::cout << BOLD << BLUE << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        rrf = someRandomIntern.makeForm("presidential pardon", "athena");
        if (rrf != NULL)
        {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
            rrf = NULL;
        }
    }
    return 0;
}
