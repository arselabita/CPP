#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

    std::cout << "Constructors" << std::endl;

    ClapTrap clap("Clappy");
    clap.attack("Enemy");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap" << std::endl;

    ScavTrap scav("Guardian");
    scav.attack("Enemy1");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap: Testing ATTACK" << std::endl;

    for (int i = 0; i < 30; i++)
        scav.attack("Dummy");

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap: Testing HIT POINTS" << std::endl;

    scav.takeDamage(150);
    scav.attack("Dummy");
    scav.beRepaired(5);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap: Testing COPY CONSTRUCTORS" << std::endl;

    ScavTrap copy(scav);
    copy.attack("CopyTarget");
    copy.guardGate();

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap: Testing ASSIGNMENT OP" << std::endl;

    ScavTrap assignment("Temp");
    assignment = copy;

    assignment.attack("AssignmentTarget");
    assignment.guardGate();
    std::cout << "---------------------------" << std::endl;

    return 0;
}