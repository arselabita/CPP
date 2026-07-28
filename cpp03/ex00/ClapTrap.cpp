#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hitPoints(0), _energyPoints(0), _attackDamage(0)
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
ClapTrap::ClapTrap(const std::string &name) : _name(name)
{
}

void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << _name << " attacks" << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
}
void ClapTrap::beRepaired(unsigned int amount)
{
}