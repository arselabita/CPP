#include "easyfind.hpp"

int main()
{
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << CYAN << "\nTesting: std::vector<int> (Element Exists): " << RESET << std::endl;
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        int target = 3;
        try
        {
            std::vector<int>::iterator it = easyfind<std::vector<int> >(v, target);
            std::cout << "The element is: " << *it << std::endl;
        }
        catch (const Error::NotFoundElement &e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << CYAN << "\nTesting: std::vector<int> (Proof that it found the 1st element): " << RESET << std::endl;
    std::cout << BOLD << CYAN << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        std::vector<int> v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);

        int target = 3;
        try
        {
            std::vector<int>::iterator it = easyfind<std::vector<int> >(v, target);
            std::cout << "The element is: " << *it << "\n" << std::endl;

            std::cout << "Before:" << std::endl;
            for (size_t i = 0; i < v.size(); i++)
                std::cout << v[i] << " ";
            std::cout << "\n";

            *it = 34;
            std::cout << "\n";
            std::cout << "After:" << std::endl;
            for (size_t i = 0; i < v.size(); i++)
                std::cout << v[i] << " ";
            std::cout << "\n";
        }
        catch (const Error::NotFoundElement &e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "\nTesting: std::list<int> (Element Does NOT Exist): " << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        std::list<int> l;
        l.push_back(42);
        l.push_back(29);
        l.push_back(70);

        int target = 30;

        try
        {
            std::list<int>::iterator it = easyfind<std::list<int> >(l, target);
            std::cout << "The element is: " << *it << std::endl;
        }
        catch (const Error::NotFoundElement &e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------" << RESET << std::endl;
    std::cout << BOLD << YELLOW << "\nTesting: std::list<int> (Element Does NOT Exist): " << RESET << std::endl;
    std::cout << BOLD << YELLOW << "--------------------------------------------------------------------\n"
              << RESET << std::endl;
    {
        std::deque<int> d;
        d.push_back(100);
        d.push_back(200);
        d.push_back(300);
        d.push_back(400);
        d.push_back(500);

        int target = 400;

        try
        {
            std::deque<int>::iterator it = easyfind<std::deque<int> >(d, target);
            std::cout << "The element is: " << *it << std::endl;
        }
        catch (const Error::NotFoundElement &e)
        {
            std::cerr << RED << e.what() << RESET << std::endl;
        }
    }
    return 0;
}