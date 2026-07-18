#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    // std::cout << "Constructor: " << name << " | " << this << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " was destroyed" << std::endl;
    // std::cout << "Destructor: " << name << " | " << this << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": " << "BraiiiiiiinnnzzzZ\n";
}
