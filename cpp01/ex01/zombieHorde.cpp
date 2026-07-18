#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cerr << "Invalid input. Pass a valid number.\n";
        return NULL;
    }
    Zombie* horde = new Zombie[N];
    if (horde == NULL)
        std::cerr << "Memory allocation failed.\n";
    for (int i = 0; i < N; i++)
        horde[i].setZombieName(name);
    return horde;
}