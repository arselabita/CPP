#include "Zombie.hpp"

int main()
{
    std::string userInput;
    std::cout << "Enter name: ";
    std::cin >> userInput;

    Zombie *zombie1 = newZombie(userInput);
    zombie1->announce();
    delete zombie1;
    randomChump(userInput);
    return EXIT_SUCCESS;
}