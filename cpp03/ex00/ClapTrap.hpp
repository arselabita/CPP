#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
public:
    ClapTrap(void);                          // Constructor
    ClapTrap(const ClapTrap &original);      // Copy constructor
    ClapTrap &operator=(const ClapTrap &original); // Copy assignment operator
    ~ClapTrap(void); // Destructor

    ClapTrap(const std::string &name);

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:
    std::string _name;
    int _hitPoints = 10;
    int _energyPoints = 10;
    int _attackDamage = 0;
};

#endif