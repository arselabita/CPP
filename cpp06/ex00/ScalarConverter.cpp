#include "ScalarConverter.hpp"

void showError(const std::string &errorStr)
{
    std::cerr << RED << "\n"
              << errorStr << RESET;
    std::cerr << "\n"
              << std::string(50, '-') << "\n";
}

bool ScalarConverter::isInt(const std::string &strInput)
{
    size_t start = 0;

    if (strInput.empty())
        return false;
    if (strInput[0] == '-' || strInput[0] == '+')
    {
        if (strInput.length() == 1)
            return false;
        start = 1;
    }
    for (size_t i = start; i < strInput.length(); i++)
    {
        if (!std::isdigit(strInput[i]))
            return false;
    }
    return true;
}

LiteralType ScalarConverter::detectType(const std::string &strInput)
{
    // if (isChar(strInput))
    //     return CHAR;
    if (isInt(strInput))
        return INT;
    // if (isFloat(strInput))
    //     return FLOAT;
    // if (isDouble(strInput))
    //     return DOUBLE;
    // if (isPseudo(strInput))
    //     return PSEUDO;
    return INVALID;
}
// void ScalarConverter::printValue(char chValue, int iValue, float fValue, double dValue)
// {

//     std::cout << "float: " << fValue << std::endl;
//     std::cout << "double: " << dValue << std::endl;
// }
void ScalarConverter::castValues(int number)
{
    if (number <= std::numeric_limits<int>::max() && number >= std::numeric_limits<int>::min())
    {
        int iValue = static_cast<int>(number);
        std::cout << "int: " << iValue << std::endl;
    }
    else
        std::cout << "int: impossible" << std::endl;

    char chValue = static_cast<char>(number);
    if (chValue < 0 || chValue > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        if (std::isprint(chValue))
            std::cout << "char: " << chValue << std::endl;
        else
            std::cout << "char: not displayable" << std::endl;
    }

    if (number >= std::numeric_limits<float>::lowest() && number <= std::numeric_limits<float>::max())
    {
        float fValue = static_cast<float>(number);
        std::cout << "float: " << fValue << std::endl;
    }
    else
        std::cout << "float: impossible" << std::endl;

    if (number >= std::numeric_limits<double>::lowest() && number <= std::numeric_limits<double>::max())
    {
        double dValue = static_cast<double>(number);
        std::cout << "double: " << dValue << std::endl;
    }
    else
        std::cout << "double: impossible" << std::endl;
    // printValue(chValue, iValue, fValue, dValue);
}
void ScalarConverter::parseValue(const std::string &strInput, LiteralType type)
{
    char *endptr;
    int number = 0;
    switch (type)
    {
    // case CHAR:
    //     /* code */
    //     break;
    case INT:
        number = strtol(strInput.c_str(), &endptr, 10);
        if (*endptr != '\0')
        {
            std::cerr << "Conversion stopped at: " << endptr << std::endl;
            break;
        }
        castValues(number);
        break;
    // case FLOAT:
    //     break;
    // case DOUBLE:
    //     break;
    // case PSEUDO:
    //     break;
    default:
        std::cerr << "Not Found" << std::endl;
        break;
    }
}
void ScalarConverter::convert(const std::string &strInput)
{
    LiteralType type = detectType(strInput);
    parseValue(strInput, type);
}