#include "ScalarConverter.hpp"

void showError(const std::string &errorStr)
{
    std::cerr << RED << errorStr << RESET << std::endl;
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
bool ScalarConverter::isChar(const std::string &strInput)
{
    if (strInput.empty())
        return false;
    if (strInput.length() == 1 && !std::isdigit(strInput[0]))
        return true;
    if (strInput.length() == 3 && strInput[0] == '\'' && strInput[2] == '\'')
        return true;
    return false;
}
LiteralType ScalarConverter::detectType(const std::string &strInput)
{
    if (isChar(strInput))
        return CHAR;
    if (isInt(strInput))
        return INT;
    // if (isFloat(strInput))
    //     return FLOAT;
    // if (isDouble(strInput))
    //     return DOUBLE;
    return INVALID;
}

void ScalarConverter::castValues(long int number)
{
    if (number < 0 || number > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        char chValue = static_cast<char>(number);
        if (std::isprint(chValue))
            std::cout << "char: '" << chValue << "'" << std::endl;
        else
            std::cout << "char: not displayable" << std::endl;
    }

    int iValue = static_cast<int>(number);
    std::cout << "int: " << iValue << std::endl;

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
}
void ScalarConverter::parseValue(const std::string &strInput, LiteralType type)
{

    switch (type)
    {
    case CHAR:
    {
        char ch;
        if (strInput.length() == 3 && strInput[0] == '\'' && strInput[2] == '\'')
            ch = strInput[1];
        else
            ch = strInput[0];
        castValues(static_cast<int>(ch));
    }
    break;
    case INT:
    {
        errno = 0;
        char *endptr;
        long number;
        number = strtol(strInput.c_str(), &endptr, 10);
        if (strInput.c_str() == endptr || *endptr != '\0')
        {
            std::cerr << "Invalid integer format!" << std::endl;
            break;
        }
        if (errno == ERANGE || number > INT_MAX || number < INT_MIN)
        {
            std::cerr << "Integer out of bounds!" << std::endl;
            break;
        }
        castValues(static_cast<int>(number));
        break;
    }
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