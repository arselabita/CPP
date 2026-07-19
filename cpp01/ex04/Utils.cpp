#include "Utils.hpp"

void showError(const std::string &errorStr)
{
    std::cerr << RED_TXT << "\n"
              << errorStr << "\n"
              << RESET;
}
bool argCheck(int ac)
{
    if (ac != 4)
    {
        showError("Please pass 3 parameters: <filename> <s1> <s2>.");
        return false;
    }
    return true;
}
bool readFile(std::string &filePath)
{
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        showError("Failed to open file.");
        return false;
    }
    std::string fileText, fileContent;
    while (std::getline(file, fileText))
        fileContent += fileText + '\n';
    std::cout << fileContent;
    
    file.close();
    return true;
}
