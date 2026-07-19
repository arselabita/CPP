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
bool argCheck(int ac);

bool readFile(std::string &filePath);


#endif