#include "Zombie.hpp"

int main()
{
    std::string name;
    int num;

    std::cout << "Enter a name: ";
    std::cin >> name;
    std::cout << "Enter a number: ";
    std::cin >> num;

    Zombie* zombie = zombieHorde(num, name);
    if (zombie == NULL)
        return EXIT_FAILURE;
    for (int i = 0; i < num; i++)
        zombie[i].announce();
    delete[] zombie;
    return EXIT_SUCCESS;
}