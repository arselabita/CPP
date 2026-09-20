#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &original)
{
    (void)original;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &original)
{
    (void)original;
    return *this;
}
ScalarConverter::~ScalarConverter() {}

void showError(const std::string &errorStr)
{
    std::cerr << RED << errorStr << RESET << std::endl;
}
bool ScalarConverter::isPseudo(const std::string &strInput)
{
    if (strInput.empty())
        return false;
    return (strInput == "nan" || strInput == "nanf" ||
            strInput == "-inff" || strInput == "+inff" ||
            strInput == "-inf" || strInput == "+inf");
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
bool ScalarConverter::isFloat(const std::string &strInput)
{
    size_t start = 0;
    bool isDot = false;
    bool hasDigit = false;

    if (strInput.empty() || strInput[strInput.length() - 1] != 'f')
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
        else if (std::isdigit(strInput[i]))
            hasDigit = true;
        else
            return false;
    }
    return isDot && hasDigit;
}

bool ScalarConverter::isDouble(const std::string &strInput)
{
    size_t start = 0;
    bool isDot = false;
    bool hasDigit = false;

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
        else if (std::isdigit(strInput[i]))
            hasDigit = true;
        else
            return false;
    }
    return isDot && hasDigit;
}

void ScalarConverter::castValues(double number)
{
    // To determine if a value is NaN, a comparison of the value to itself is surprisingly effective
    bool isNan = number != number;
    // char conversion
    if (isNan || number < 0 || number > 127)
        std::cout << "char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(number)))
        std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
    else
        std::cout << "char: not displayable" << std::endl;

    // int conversion
    if (isNan || number > INT_MAX || number < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(number) << std::endl;
    // float conversion
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
    // double conversion
    std::cout << "double: " << static_cast<double>(number) << std::endl;
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
        castValues(static_cast<double>(ch));
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
        castValues(static_cast<double>(number));
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
            castValues(std::numeric_limits<double>::quiet_NaN());
        else if (strInput == "-inf" || strInput == "-inff")
            castValues(-std::numeric_limits<double>::infinity());
        else if (strInput == "+inf" || strInput == "+inff")
            castValues(std::numeric_limits<double>::infinity());
        break;
    }
    case INVALID:
    default:
        std::cerr << "Invalid literal type!" << std::endl;
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