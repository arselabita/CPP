#include "Bureaucrat.hpp"

int main()
{
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << CYAN << "\nTesting: Normal input, just creating the object and printing it out." << RESET << std::endl;
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat hermes("Hermes", 3);
            std::cout << "Before: " << hermes << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Unexpected Failure: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "\nTesting: Incrementing the grade and the output is valid." << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat hera("Hera", 2);

            std::cout << "Before: " << hera << std::endl;
            hera.incrementGrade();
            std::cout << GREEN << "After: " << hera << RESET << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << RED << "GradeTooHighException Failed: " << e.what() << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "std::exception failed: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << YELLOW << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "\nTesting: Incrementing the grade and the output is invalid." << RESET << std::endl;
    std::cout << BOLD << YELLOW << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat athena("Athena", 1);

            std::cout << "Before: " << athena << std::endl;
            athena.incrementGrade();
            std::cout << GREEN << "After: " << athena << RESET << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << RED << "Failed: " << "!! GradeTooHighException: " << e.what() << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "!! std::exception failed: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << BLUE << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << BLUE << "\nTesting: Decrementing the grade and the output is valid." << RESET << std::endl;
    std::cout << BOLD << BLUE << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat athena("Athena", 140);

            std::cout << "Before: " << athena << std::endl;
            athena.decrementGrade();
            std::cout << GREEN << "Updated: " << athena << RESET << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << RED << "Failed: " << "!! GradeTooLowException: " << e.what() << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "!! std::exception failed: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << MAGENTA << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "\nTesting: Decrementing the grade and the output is invalid." << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat athena("Athena", 150);

            std::cout << "Before: " << athena << std::endl;
            athena.decrementGrade();
            std::cout << GREEN << "Updated: " << athena << RESET << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << RED << "Failed: " << "!! GradeTooLowException: " << e.what() << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "!! std::exception failed: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << YELLOW << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "\nTesting: Invalid value in constructors." << RESET << std::endl;
    std::cout << BOLD << YELLOW << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat athena("Athena", 151);

            std::cout << "Before: " << athena << std::endl;
            athena.decrementGrade();
            std::cout << GREEN << "Updated: " << athena << RESET << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << RED << "Failed: " << "!! GradeTooLowException: " << e.what() << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "!! std::exception failed: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << BLUE << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << BLUE << "\nTesting: Invalid value in constructors." << RESET << std::endl;
    std::cout << BOLD << BLUE << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat athena("Athena", 0);

            std::cout << "Before: " << athena << std::endl;
            athena.decrementGrade();
            std::cout << GREEN << "Updated: " << athena << RESET << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << RED << "Failed: " << "!! GradeTooLowException: " << e.what() << RESET << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "!! std::exception failed: " << e.what() << RESET << std::endl;
        }
    }
    return 0;
}