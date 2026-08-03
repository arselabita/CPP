#include "ClapTrap.hpp"

int main()
{
    ClapTrap first;
    std::cout << "\n";
    std::cout << "\n";

    ClapTrap a("Arsela");
    a.attack("Hidri");
   
    a.takeDamage(2);

    a.attack("Hidri");
    a.attack("Hidri");
    a.attack("Hidri");

    a.takeDamage(15);
    a.beRepaired(2);

    a.beRepaired(2);

    std::cout << "\n";

    std::cout << "Copy assignment\n";

    ClapTrap b;
    a = b;

    b.attack("Arsela");
    b.attack("You");
    b.beRepaired(1);
    b.takeDamage(4);

    std::cout << "\n";

    std::cout << "Copy obj\n";
    ClapTrap copy(a);
    copy.attack("Stela");
    copy.beRepaired(3);
    copy.attack("Stela");
    copy.attack("Stela");
    copy.attack("Stela");
    copy.attack("Stela");
    copy.takeDamage(2);
    copy.takeDamage(2);
    copy.takeDamage(2);
    copy.takeDamage(2);
    std::cout << "\n";

    return 0;
}