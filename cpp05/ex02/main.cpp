#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "\nTesting: Unsigned Form Execution." << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat oddissey("Oddissey", 130);
            ShrubberyCreationForm form("agamemnon");

            std::cout << form << std::endl;
            oddissey.executeForm(form);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Unexpected Failure: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << CYAN << "\nTesting ShrubberyCreationForm: Signed Form Execution." << RESET << std::endl;
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat odyssey("Odyssey", 2);
            ShrubberyCreationForm shForm("agamemnon");

            std::cout << "Initial form: " << shForm << std::endl;
            shForm.beSigned(odyssey);
            odyssey.executeForm(shForm);
            std::cout << "Final status: " << shForm << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Unexpected Failure: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "\nTesting RobotomyRequestForm: Signed Form Execution." << RESET << std::endl;
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat hermes("Hermes", 20);
            RobotomyRequestForm rForm("Hermes");

            std::cout << "\nInitial form: " << rForm << std::endl;
            rForm.beSigned(hermes);
            hermes.executeForm(rForm);
            std::cout << "\nFinal status: " << rForm << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Unexpected Failure: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << BLUE << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << BLUE << "\nTesting RobotomyRequestForm: Signed Form Execution. (loop)" << RESET << std::endl;
    std::cout << BOLD << BLUE << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat hermes("Hermes", 20);
            RobotomyRequestForm rForm("Hermes");

            std::cout << "\nInitial form: " << rForm << std::endl;
            hermes.signForm(rForm);
            for (int i = 0; i < 4; i++)
            {
                std::cout << "\n--- Execution attempt: " << (i + 1) << " ---" << std::endl;
                hermes.executeForm(rForm);
            }
            std::cout << "\nFinal status: " << rForm << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Unexpected Failure: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "\nTesting PresidentialPardonForm: Signed Form Execution." << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat president("Zaphod", 25);
            Bureaucrat hera("Hera", 5);

            PresidentialPardonForm pForm("Someone");

            president.signForm(pForm);
            std::cout << YELLOW << "\n---Attempting execution with a insufficient grade (25)---"<< RESET << std::endl;
            president.executeForm(pForm);
            std::cout << GREEN << "\n---Attempting execution with a sufficient grade (5)---"<< RESET << std::endl;
            hera.executeForm(pForm);
            std::cout << "\nFinal status: " << pForm << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Unexpected Failure: " << e.what() << RESET << std::endl;
        }
    }
    return 0;
}