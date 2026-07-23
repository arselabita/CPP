#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) :  _weapon(nullptr), _name(name)
{
    return;
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}
void HumanB::attack()
{
    if (!_weapon)
        std::cout << "Carefulll" << std::endl;
    else
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}