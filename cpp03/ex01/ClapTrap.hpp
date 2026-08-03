#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
public:
    ClapTrap(void);
    ClapTrap(const std::string &name, unsigned int hP, unsigned int eP, unsigned int aD);
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &original);
    ClapTrap &operator=(const ClapTrap &original);
    ~ClapTrap(void);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
};

#endif