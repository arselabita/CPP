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
    std::cout << "Constructor called\n";
}
void ClapTrap::setHitPoints(int hitPoints)
{
    _hitPoints = hitPoints;
}
int ClapTrap::getHitPoints(void) const
{
    return _hitPoints;
}
void ClapTrap::setAttack(int attack)
{
    _attackDamage = attack;
}
int ClapTrap::getAttack(void) const
{
    return _attackDamage;
}

void ClapTrap::setEnergy(int energy)
{
    _energyPoints = energy;
}
int ClapTrap::getEnergy(void) const
{
    return _energyPoints;
}
void ClapTrap::attack(const std::string &target)
{
    std::cout << "ClapTrap " << _name << " attacks " << target << " , causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints -= 1;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name << " damages by " << amount << " , causing " << _attackDamage << " points of damage!" << std::endl;

    _attackDamage = _attackDamage + amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0 || _energyPoints == 0)
        std::cout << "Oppss! Seems like you ran out of Hit/Energy Points\n";
    std::cout << "ClapTrap " << _name << " repairs by " << amount << " and gains " << _hitPoints << " points of health!" << std::endl;

    _hitPoints = _hitPoints + amount;
    _energyPoints += 1;
}