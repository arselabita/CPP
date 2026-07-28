#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("nope"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &original) : _name(original._name), _hitPoints(original._hitPoints),
                                               _energyPoints(original._energyPoints), _attackDamage(original._attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &original)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &original)
    {
        this->_name = original._name;
        this->_hitPoints = original._hitPoints;
        this->_energyPoints = original._energyPoints;
        this->_attackDamage = original._attackDamage;
    }
    return *this;
}
ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
}
void ClapTrap::setHitPoints(int hitPoints)
{
    _hitPoints = hitPoints;
}
int ClapTrap::getHitPoints(void) const
{
    return _hitPoints;
}
void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
    _attackDamage--;
}
// void ClapTrap::takeDamage(unsigned int amount)
// {
// }
void ClapTrap::beRepaired(unsigned int amount)
{
    _hitPoints = _hitPoints + amount;
}