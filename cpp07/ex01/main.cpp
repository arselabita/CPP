#include "iter.hpp"

template <typename T, typename Function>
void iter(T *arrPtr, const size_t length, Function addVal)
{
    for (size_t i = 0; i < length; i++)
        addVal(arrPtr[i]);
}
void add(int &num)
{
    num += num;
}
void multipy(double &num)
{
    num *= num;
}
void print(const std::string &str)
{
    std::cout << "My name is: " << str << std::endl;
}
int main()
{
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Function (non-const funct pointer and using int):\n"
              << std::endl;
    {
        int arr[5] = {1, 2, 3, 4, 5};
        iter(arr, 5, add);

        for (int i = 0; i < 5; i++)
            std::cout << arr[i] << std::endl;
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Function (const funct pointer and using string):\n"
              << std::endl;
    {
        std::string arr[5] = {"Arsela", "Anja", "Xhennet", "Hidri", "Orion"};
        iter(arr, 5, print);
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Template Function (non-const and using double):\n"
              << std::endl;
    {
        double arr[5] = {1.1, 1.2, 3.4, 5.6, 7.9};
        iter(arr, 5, multipy);

        for (int i = 0; i < 5; i++)
            std::cout << arr[i] << std::endl;
    }
    return 0;
}