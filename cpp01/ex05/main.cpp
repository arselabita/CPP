#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "DEBUG CALLED: " << std::endl; 
    harl.complain("DEBUG");
    std::cout << "INFO CALLED: " << std::endl; 
    harl.complain("INFO");
    std::cout << "WARNING CALLED: " << std::endl; 
    harl.complain("WARNING");
    std::cout << "ERROR CALLED: " << std::endl; 
    harl.complain("ERROR");


    //Invalid input
    std::cout << "INVALID CALLED: " << std::endl; 
    harl.complain("ERRR");
    return EXIT_SUCCESS;
}