#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack();

private:
    Weapon& _weapon;
    std::string _name;
};

#endif