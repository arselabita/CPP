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

ClapTrap::ClapTrap(const std::string &name) : _name(name),
                                            _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Constructor called\n";
}

void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
    { 
        std::cout << "Oppss! Seems like you ran out of Hit/Energy Points\n";
        return;
    }
    _energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " 
                            << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "Oppss! Seems like you ran out of hit points!\n";
        return ;
    }
    if (amount > _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                << " points of damage, reducing its hit points to " << _hitPoints << std::endl;
        return ;
    }
    _hitPoints = _hitPoints - amount;
    std::cout << "ClapTrap received a damage of " << amount 
                << " , decreasing hit points to " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0 || _energyPoints == 0)
    {
        std::cout << "Oppss! Seems like you ran out of Hit/Energy Points\n";
        return ;
    }
    _hitPoints = _hitPoints + amount;
    _energyPoints -= 1;
    std::cout << "ClapTrap " << _name << " repairs itself by " << amount << " hit points" << std::endl;
}
