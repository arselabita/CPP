#pragma once

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[m"

#include <string>
#include <iostream>
#include <limits>
#include <cfloat>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <iomanip>
#include <exception>

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

class ScalarConverter
{
public:
    static void convert(const std::string &strInput);

private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &original);
    ScalarConverter &operator=(const ScalarConverter &original);
    ~ScalarConverter();

    static LiteralType detectType(const std::string &strType);
    static void parseValue(const std::string &strInput, LiteralType type);
    static void castValues(double number);

    static bool isPseudo(const std::string &strInput);
    static bool isChar(const std::string &strInput);
    static bool isInt(const std::string &strInput);
    static bool isFloat(const std::string &strInput);
    static bool isDouble(const std::string &strInput);
};
void showError(const std::string &errorStr);
