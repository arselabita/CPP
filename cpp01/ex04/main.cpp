#include "Utils.hpp"

int main(int ac, char **av)
{
    if (!argCheck(ac))
        return EXIT_FAILURE;
    std::string filePath = av[1], s1 = av[2], s2 = av[3];
    if (s1.empty())
        return showError("The 2nd argument (s1) should not be empty!"), EXIT_FAILURE;
    if (!readFile(filePath, s1, s2))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}