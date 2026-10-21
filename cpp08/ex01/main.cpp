#include "Span.hpp"

int main()
{
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << CYAN << "\nTesting: 42 main: " << RESET << std::endl;
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Span sp = Span(5);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            std::cout << "Shortest Span: ";
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << "Longest Span: ";
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "\nTesting: exception handling (when it exceeds the capacity): " << RESET << std::endl;
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Span sp = Span(2);
            sp.addNumber(1);
            sp.addNumber(4);
            sp.addNumber(7);

            std::cout << "Shortest Span: ";
            std::cout << sp.shortestSpan() << std::endl;

            std::cout << "Longest Span: ";
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << BOLD << BLUE << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << BLUE << "\nTesting: exception handling (when it doesnt have enough elements): " << RESET << std::endl;
    std::cout << BOLD << BLUE << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Span sp = Span(2);
            sp.addNumber(1);

            std::cout << "Shortest Span: ";
            std::cout << sp.shortestSpan() << std::endl;

            std::cout << "Longest Span: ";
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "\nTesting: with a 10,000 (range iterator implementation): " << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        try
        {
            Span sp = Span(10000);

            std::vector<unsigned int> tempVector;
            for (int i = 0; i < 10000; i++)
                tempVector.push_back(i);

            sp.addNumberOnRange(tempVector.begin(), tempVector.end());

            std::cout << "Shortest Span: ";
            std::cout << sp.shortestSpan() << std::endl;

            std::cout << "Longest Span: ";
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "\nTesting: with a random numbers (range iterator implementation): " << RESET << std::endl;
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        srand(time(0));
        try
        {
            Span sp = Span(20000);

            std::list<unsigned int> tempVector;
            int randomNum = 0;
            for (int i = 0; i < 20000; i++)
            {
                randomNum = rand() % 20000;
                tempVector.push_back(randomNum);
            }

            sp.addNumberOnRange(tempVector.begin(), tempVector.end());

            std::cout << "Shortest Span: ";
            std::cout << sp.shortestSpan() << std::endl;

            std::cout << "Longest Span: ";
            std::cout << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}