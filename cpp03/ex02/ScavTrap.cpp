#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Derived ScavTrap class default constructor called" << std::endl;
    _name = "nope";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "Derived ScavTrap class constructor called" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original)
{
    (void)original;
    std::cout << "Derived ScavTrap class copy constructor called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &original)
{
    std::cout << "Derived ScavTrap class copy assignment operator called" << std::endl;
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
    std::cout << "Derived ScavTrap class destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (_hitPoints < 1)
    {
        std::cout << "Oppss! Seems like you ran out of Hit Points" << std::endl;
        return;
    }
    if (_energyPoints < 1)
    {
        std::cout << "Oppss! Seems like you ran out of Energy Points" << std::endl;
        return;
    }
    _energyPoints -= 1;
    std::cout << "ScavTrap " << _name << " attacks " << target << " , causing "
              << _attackDamage << " points of damage!" << std::endl;
}
void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
