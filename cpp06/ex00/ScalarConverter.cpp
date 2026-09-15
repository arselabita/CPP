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

bool ScalarConverter::isFloat(const std::string &strInput)
{
    size_t start = 0;
    bool isDot = false;

    if (strInput.empty())
        return false;
    if (strInput[strInput.length() - 1] != 'f')
        return false;
    if (strInput[0] == '-' || strInput[0] == '+')
    {
        if (strInput.length() == 1)
            return false;
        start = 1;
    }
    for (size_t i = start; i < strInput.length() - 1; i++)
    {
        if (strInput[i] == '.')
        {
            if (isDot == true)
                return false;
            isDot = true;
        }
        else if (!std::isdigit(strInput[i]))
            return false;
    }
    return isDot;
}

bool ScalarConverter::isDouble(const std::string &strInput)
{
    size_t start = 0;
    bool isDot = false;

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
        if (strInput[i] == '.')
        {
            if (isDot == true)
                return false;
            isDot = true;
        }
        else if (!std::isdigit(strInput[i]))
            return false;
    }
    return isDot;
}
bool ScalarConverter::isPseudo(const std::string &strInput)
{
    if (strInput.empty())
        return false;
    if (strInput == "nan" || strInput == "nanf" || 
        strInput == "-inff" || strInput == "+inff" ||
        strInput == "-inf" || strInput == "+inf")
            return true;
    return false;
}

void ScalarConverter::castValues(double number)
{
    // char conversion
    if (number < 0 || number > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(number)))
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    else
        std::cout << "char: not displayable" << std::endl;

    // int conversion
    if (number > INT_MAX || number < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;

    // float conversion
    if (number >= std::numeric_limits<float>::lowest() && number <= std::numeric_limits<float>::max())
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
    else
        std::cout << "float: impossible" << std::endl;

    // double conversion
    if (number >= std::numeric_limits<double>::lowest() && number <= std::numeric_limits<double>::max())
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
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
        castValues(static_cast<float>(ch));
    }
    break;
    case INT:
    {
        errno = 0;
        char *endptr;
        long number = strtol(strInput.c_str(), &endptr, 10);
        if (strInput.c_str() == endptr || *endptr != '\0')
        {
            std::cerr << "Invalid integer format!" << std::endl;
            break;
        }
        if (errno == ERANGE || number > INT_MAX || number < INT_MIN)
        {
            std::cerr << "Integer out of bounds!" << std::endl;
            errno = 0;
            break;
        }
        castValues(static_cast<float>(number));
        break;
    }
    case FLOAT:
    {
        errno = 0;
        char *endptr;
        float number = strtof(strInput.c_str(), &endptr);
        if (strInput.c_str() == endptr || *endptr != 'f' || *(endptr + 1) != '\0')
        {
            std::cerr << "Invalid float format!" << std::endl;
            break;
        }
        if (errno == ERANGE || number > FLT_MAX || number < -FLT_MAX)
        {
            std::cerr << "Float out of bounds!" << std::endl;
            errno = 0;
            break;
        }
        castValues(static_cast<float>(number));
        break;
    }
    case DOUBLE:
    {
        errno = 0;
        char *endptr;
        double number = strtod(strInput.c_str(), &endptr);
        if (strInput.c_str() == endptr || *endptr != '\0')
        {
            std::cerr << "Invalid double format!" << std::endl;
            break;
        }
        if (errno == ERANGE || number > DBL_MAX || number < -DBL_MAX)
        {
            std::cerr << "Double out of bounds!" << std::endl;
            errno = 0;
            break;
        }
        castValues(number);
        break;
    }
    case PSEUDO:
    {
        if (strInput == "nan" || strInput == "nanf")


        break;
    }
    default:
        std::cerr << "Not Found" << std::endl;
        break;
    }
}
LiteralType ScalarConverter::detectType(const std::string &strInput)
{
    if (isPseudo(strInput))
        return PSEUDO;
    if (isChar(strInput))
        return CHAR;
    if (isInt(strInput))
        return INT;
    if (isFloat(strInput))
        return FLOAT;
    if (isDouble(strInput))
        return DOUBLE;
    return INVALID;
}
void ScalarConverter::convert(const std::string &strInput)
{
    LiteralType type = detectType(strInput);
    parseValue(strInput, type);
}