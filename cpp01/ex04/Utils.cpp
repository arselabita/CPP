#include "Utils.hpp"

void showInfo(const std::string &infoStr)
{
    std::cerr << GREEN_TXT << "\n"
              << infoStr << "\n"
              << RESET;
}

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
bool readFile(const std::string& filePath, const std::string& s1, const std::string& s2)
{
    std::ifstream originalFile(filePath);
    std::string pathName, fileText, fileContent;
int count = 0;
    if (!originalFile.is_open())
        return showError("Failed to open file."), false;
    pathName = filePath + ".replace";
    std::ofstream copyFile(pathName);
    if (!copyFile)
        return showError("Failed creating file."), false;
    while (std::getline(originalFile, fileText))
    {
        if (fileText == s1)
        {
            fileText = s2;
            count++;
        }
        std::cout << "counter: " << count <<"\n";
        fileContent += fileText + '\n';
    }
    copyFile << fileContent;
    if (!originalFile.eof())
        return showError("File reading failed"), false;
    copyFile.close();
    originalFile.close();
    return true;
}
