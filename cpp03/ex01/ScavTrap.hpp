#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &original);
    ScavTrap &operator=(const ScavTrap &original);
    ~ScavTrap(void);

    void attack(const std::string &target);
    void guardGate(void);
};
#endif