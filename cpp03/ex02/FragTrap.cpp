#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Derived FragTrap class default constructor called" << std::endl;
    _name = "nope";
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "Derived FragTrap class constructor called" << std::endl;
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original)
{
    (void)original;
    std::cout << "Derived FragTrap class copy constructor called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &original)
{
    std::cout << "Derived FragTrap class copy assignment operator called" << std::endl;
    if (this != &original)
    {
        this->_name = original._name;
        this->_hitPoints = original._hitPoints;
        this->_energyPoints = original._energyPoints;
        this->_attackDamage = original._attackDamage;
    }
    return *this;
}
FragTrap::~FragTrap(void)
{
    std::cout << "Derived FragTrap class destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requests a high-five to " << _name << ": positive" << std::endl;
}