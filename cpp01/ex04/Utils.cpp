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
bool readFile(const std::string &filePath, const std::string &s1, const std::string &s2)
{
    std::ifstream originalFile(filePath);
    std::string pathName, fileText, fileContent;

    if (!originalFile.is_open())
        return showError("Failed to open file."), false;
    pathName = filePath + ".replace";
    std::ofstream copyFile(pathName);
    if (!copyFile)
        return showError("Failed creating file."), false;
    while (std::getline(originalFile, fileText))
    {
        std::string newStr = "";
        size_t currPos = 0;
        size_t foundPos = fileText.find(s1, currPos);
        while (foundPos != std::string::npos)
        {
            newStr.append(fileText, currPos, foundPos - currPos);
            newStr.append(s2);
            currPos = foundPos+s1.length();
            foundPos = fileText.find(s1, currPos);
        }
        newStr.append(fileText, currPos, std::string::npos);
        fileContent += newStr + '\n';
    }
    copyFile << fileContent;
    if (!originalFile.eof())
        return showError("File reading failed"), false;
    copyFile.close();
    originalFile.close();
    return true;
}
