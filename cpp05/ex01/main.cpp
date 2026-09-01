#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    std::cout << BOLD << MAGENTA << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "\nTesting: Form signed." << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat aphrodite("Aphrodite", 3);
            Form formOne("One", 4, 2, false);

            std::cout << "Before: " << formOne << std::endl;
            formOne.beSigned(aphrodite);
            std::cout << GREEN << "After: " << formOne << RESET;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << CYAN << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << CYAN << "\nTesting: Bureaucrat::signedForm wrapper." << RESET << std::endl;
    std::cout << BOLD << CYAN << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Bureaucrat boss("The boss", 10);
            Bureaucrat intern("The intern", 140);
            Form contract("TopSecretContract", 50, 20, false);

            std::cout << contract;

            intern.signForm(contract);

            boss.signForm(contract);

            std::cout << contract;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << BLUE << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << BLUE << "\nTesting: Form illegal input constructor." << RESET << std::endl;
    std::cout << BOLD << BLUE << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Form Illegal("Illegal", 0, 50, false);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
        try
        {
            Form Illegal("Illegal", 1, 151, false);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << CYAN << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << CYAN << "\nTesting: Form illegal input constructor." << RESET << std::endl;
    std::cout << BOLD << CYAN << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        // high value test
        try
        {
            Form illegal("illegal", 0, 0, false);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
        // low value test
        try
        {
            Form illegal("illegal", 151, 151, false);
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << YELLOW << "----------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "\nTesting: Signing an already signed form." << RESET << std::endl;
    std::cout << BOLD << YELLOW << "----------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try{
            Bureaucrat zeus("Zeus", 1);
            Form laws("Laws", 1, 1, false);

            zeus.signForm(laws);
            zeus.signForm(laws);

        } catch (const std::exception &e)
        {
            std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }

    return 0;
}