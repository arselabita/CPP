#pragma once

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[m"

#include <string>
#include <iostream>
#include <limits>
#include <cfloat>
#include <cctype> // covers a range of functions, also std::isprint() to cover besides letters also special chars
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <exception>

enum LiteralType{
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

    static bool isInt(const std::string &valRep);
    static bool isChar(const std::string &valRep);
    static bool isFloat(const std::string &valRep);
    static bool isDouble(const std::string &valRep);
    static bool isPseudo(const std::string &valRep);

};
void showError(const std::string &errorStr);
