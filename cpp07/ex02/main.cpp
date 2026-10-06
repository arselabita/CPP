#include "Array.hpp"

int main(int, char **)
{
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Class (Construction with no parameter):\n"
              << std::endl;
    {
        try
        {
            Array<int> arr();
            arr.size();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Unexpected Failure: " << e.what() << std::endl;
        }
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Class (Construction with parameter):\n"
              << std::endl;
    {
        try
        {
            Array<int> arr(5);
            arr.size();
        }
        catch (const std::exception &e)
        {
            std::cerr << "Unexpected Failure: " << e.what() << std::endl;
        }
        
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Class (Copy Constructor):\n"
              << std::endl;
    {
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Class (Assign Operator Constructor):\n"
              << std::endl;
    {
    }
    return 0;
}