#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Arsela");
    std::cout << "Hit Points Before: " << a.getHitPoints() << std::endl;
    a.attack("Hidri");
    std::cout << "Hit Points After: " << a.getHitPoints() << std::endl;

    std::cout << "\n";

    std::cout << "Hit Points Before Repair: " << a.getHitPoints() << std::endl;
    a.beRepaired(2);
    std::cout << "Hit Points After Repair: " << a.getHitPoints() << std::endl;

    return 0;
}