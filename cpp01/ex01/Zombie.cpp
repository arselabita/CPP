#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "";
}

Zombie::~Zombie()
{
    std::cout << "Zombie destroyed" << std::endl;
}
void Zombie::setZombieName(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}