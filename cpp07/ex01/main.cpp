#include "iter.hpp"
#include <iostream>

int main()
{
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Function (non-const funct pointer and using int):\n"
              << std::endl;
    {
        int arr[5] = {1, 2, 3, 4, 5};
        std::size_t arrLength = sizeof(arr) / sizeof(arr[0]);
        ::iter(arr, arrLength, add<int>);

        for (int i = 0; i < 5; i++)
            std::cout << arr[i] << std::endl;
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Function (const funct pointer and using string):\n"
              << std::endl;
    {
        const std::string arr[5] = {"Arsela", "Anja", "Xhennet", "Hidri", "Orion"};
        std::size_t arrLength = sizeof(arr) / sizeof(arr[0]);
        ::iter(arr, arrLength, print<const std::string>);
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Function (non-const and using double):\n"
              << std::endl;
    {
        double arr[5] = {1.1, 1.2, 3.4, 5.6, 7.9};
        std::size_t arrLength = sizeof(arr) / sizeof(arr[0]);
        ::iter(arr, arrLength, multiplication<double>);

        for (int i = 0; i < 5; i++)
            std::cout << arr[i] << std::endl;
    }
    return 0;
}