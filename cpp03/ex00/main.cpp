#include "ClapTrap.hpp"

int main()
{
    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap Constructor" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ClapTrap first;
    ClapTrap clap("Clappy");

    clap.attack("Enemy");
    clap.takeDamage(3);
    clap.beRepaired(2);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap: Testing ATTACK" << std::endl;
    std::cout << "---------------------------" << std::endl;

    clap.attack("Enemy");
    clap.attack("Enemy");
    clap.attack("Enemy");

    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap: Testing TAKE DAMAGE" << std::endl;
    std::cout << "---------------------------" << std::endl;

    clap.takeDamage(3);
    clap.takeDamage(2);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap: Testing BE REPAIRED" << std::endl;
    std::cout << "---------------------------" << std::endl;

    clap.beRepaired(4);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap: Testing ENERGY" << std::endl;
    std::cout << "---------------------------" << std::endl;

    for (int i = 0; i < 15; i++)
        clap.attack("Dummy");

    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap: Testing HIT POINTS" << std::endl;
    std::cout << "---------------------------" << std::endl;

    clap.takeDamage(50);
    clap.attack("Enemy");
    clap.beRepaired(5);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap: Testing COPY CONSTRUCTOR" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ClapTrap copy(first);
    copy.attack("CopyTarget");
    copy.takeDamage(2);
    copy.beRepaired(3);

    std::cout << "---------------------------" << std::endl;
    std::cout << "ClapTrap: Testing ASSIGNMENT OP" << std::endl;
    std::cout << "---------------------------" << std::endl;

    ClapTrap assignment("Temp");
    assignment = first;

    assignment.attack("AssignmentTarget");
    assignment.takeDamage(1);
    assignment.beRepaired(1);

    return 0;
}