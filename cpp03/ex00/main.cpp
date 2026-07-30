#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Arsela");
    std::cout << "Energy Points Before: " << a.getEnergy() << std::endl;
    a.attack("Hidri");
    std::cout << "Energy Points After: " << a.getEnergy() << std::endl;
    std::cout << "Attack Points Before: " << a.getAttack() << std::endl;
    a.takeDamage(2);
    std::cout << "Attack Points After: " << a.getAttack() << std::endl;
a.attack("Hidri");
a.attack("Hidri");
a.attack("Hidri");

std::cout << "\n\n jemi ketu \n\n";
    std::cout << "Attack Points Before: " << a.getAttack() << std::endl;
    a.takeDamage(15);
    std::cout << "Attack Points After: " << a.getAttack() << std::endl;
    a.beRepaired(2);

    std::cout << "\n";

    std::cout << "Hit Points Before Repair: " << a.getHitPoints() << std::endl;
    std::cout << "Energy Points Before: " << a.getEnergy() << std::endl;

    a.beRepaired(2);
    std::cout << "Hit Points After Repair: " << a.getHitPoints() << std::endl;
    std::cout << "Energy Points After: " << a.getEnergy() << std::endl;

    return 0;
}