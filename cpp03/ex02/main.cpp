#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap Test" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ClapTrap clap("Clappy");
    clap.attack("Enemy");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap Test" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ScavTrap scav("Guardian");
    scav.attack("Enemy1");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap: Testing ATTACK" << std::endl;
    std::cout << "---------------------------" << std::endl;

    for (int i = 0; i < 30; i++)
        scav.attack("Dummy");

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap: Testing HIT POINTS" << std::endl;
    std::cout << "---------------------------" << std::endl;

    scav.takeDamage(150);
    scav.attack("Dummy");
    scav.beRepaired(5);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap: Testing COPY CONSTRUCTORS" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ScavTrap copy(scav);
    copy.attack("CopyTarget");
    copy.guardGate();

    std::cout << "---------------------------" << std::endl;
    std::cout << "ScavTrap: Testing ASSIGNMENT OP" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ScavTrap assignment("Temp");
    assignment = copy;

    assignment.attack("AssignmentTarget");
    assignment.guardGate();

    std::cout << "---------------------------" << std::endl;
    std::cout << "---------------------------" << std::endl;

    std::cout << "---------------------------" << std::endl;
    std::cout << "FragTrap Test" << std::endl;
    std::cout << "---------------------------" << std::endl;

    FragTrap frag("Fraggy");

    frag.attack("Enemy");
    frag.takeDamage(40);
    frag.beRepaired(15);
    frag.highFivesGuys();

    std::cout << "---------------------------" << std::endl;
    std::cout << "FragTrap: Testing ATTACK" << std::endl;
    std::cout << "---------------------------" << std::endl;

    for (int i = 0; i < 105; i++)
        frag.attack("Dummy");

    std::cout << "---------------------------" << std::endl;
    std::cout << "FragTrap: Testing HIT POINTS" << std::endl;
    std::cout << "---------------------------" << std::endl;

    frag.takeDamage(150);
    frag.attack("Dummy");
    frag.beRepaired(20);

    std::cout << "---------------------------" << std::endl;
    std::cout << "FragTrap: Testing COPY CONSTRUCTORS" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ScavTrap scavCopy(scav);
    FragTrap fragCopy(frag);

    scavCopy.guardGate();
    fragCopy.highFivesGuys();

    std::cout << "---------------------------" << std::endl;
    std::cout << "FragTrap: Testing ASSIGNMENT OP" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ScavTrap scavAssignment("TempScav");
    FragTrap fragAssignment("TempFrag");

    scavAssignment = scav;
    fragAssignment = frag;

    scavAssignment.guardGate();
    fragAssignment.highFivesGuys();

    std::cout << "---------------------------" << std::endl;
    std::cout << "FragTrap: Just Testing" << std::endl;
    std::cout << "---------------------------" << std::endl;

    FragTrap tester("Alice");
    FragTrap testerCopy(tester);

    testerCopy.attack("Target");
    testerCopy.takeDamage(25);
    testerCopy.beRepaired(5);
    testerCopy.highFivesGuys();
    std::cout << "---------------------------" << std::endl;
    std::cout << "---------------------------" << std::endl;

    return 0;
}