#ifndef UTILS_HPP
#define UTILS_HPP

#define MAX_SIZE 8
#define GREEN_TXT "\033[32m"
#define RED_TXT "\033[31m" 
#define RESET "\033[m"

#include <string>
#include <iostream>
#include <fstream>

void showError(const std::string &errorStr);
void showInfo(const std::string &infoStr);
bool argCheck(int ac);

bool readFile(const std::string& filePath, const std::string& s1, const std::string& s2);

#endif