#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon) : _weapon(weapon), _name(name)
{
    return;
}
void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}