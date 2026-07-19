#include "Utils.hpp"

int main(int ac, char **av)
{
    if (!argCheck(ac))
        return EXIT_FAILURE;
    std::string filePath = av[1];
    if (!readFile(filePath))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}