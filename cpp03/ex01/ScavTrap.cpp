#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
    std::cout << "Derived class default constructor called\n";
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "Derived class constructor called\n";
}
ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original._name, original._hitPoints, original._energyPoints, original._attackDamage)
{
    std::cout << "Derived class copy constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &original)
{
    std::cout << "Derived class copy assignment operator called\n";
    if (this != &original)
    {
        this->_name = original._name;
        this->_hitPoints = original._hitPoints;
        this->_energyPoints = original._energyPoints;
        this->_attackDamage = original._attackDamage;
    }
    return *this;
}
ScavTrap::~ScavTrap(void)
{
    std::cout << "Derived class destructor called\n";
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "Oppss! Seems like you ran out of Hit/Energy Points\n";
        return;
    }
    _energyPoints -= 1;
    std::cout << "ScavTrap " << _name << " attacks " << target << " , causing "
              << _attackDamage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap is now in Gate keeper mode\n";
}
