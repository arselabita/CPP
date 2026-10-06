#include "Array.hpp"

#define MAX_VAL 750
int main(int, char **)
{

    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Class (Construction with parameter):\n"
              << std::endl;
    {
        try
        {
            Array<int> arr(5);
            std::cout << "Array size is: " << arr.size() << std::endl;
            for (int i = 0; i < 5; i++)
                std::cout << arr[i] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Unexpected Failure: " << e.what() << std::endl;
        }
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Deep Copy:\n"
              << std::endl;
    {
        try
        {
            Array<std::string> original(3);
            original[0] = "Arsela";
            original[1] = "Stela";
            original[2] = "Anja";

            Array<std::string> copy(original);

            copy[0] = "Orion";

            std::cout << "Original[0] (should be Arsela): " << original[0] << std::endl;
            std::cout << "Copy[0] (should be Orion): " << copy[0] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Success! Cought Unexpected Failure: " << e.what() << std::endl;
        }
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Out of Bounds:\n"
              << std::endl;
    {
        try
        {
            Array<int> arr(2);
            std::cout << arr[8] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Success! Cought Unexpected Failure: " << e.what() << std::endl;
        }
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing The 42 Main:\n"
              << std::endl;
    {
        Array<int> numbers(MAX_VAL);
        int *mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        // SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete[] mirror; //
    }
    return 0;
}