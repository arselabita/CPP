#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
public:
    ClapTrap(void);                                // Constructor
    ClapTrap(const ClapTrap &original);            // Copy constructor
    ClapTrap &operator=(const ClapTrap &original); // Copy assignment operator
    ~ClapTrap(void);                               // Destructor

    ClapTrap(const std::string &name);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    int getHitPoints(void) const;
    void setHitPoints(int hitPoints);
    void setAttack(int attack);
    int getAttack(void) const;
    void setEnergy(int energy);
    int getEnergy(void) const;

private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif