#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

    return 0;
}