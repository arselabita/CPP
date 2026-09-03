#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& original);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm& original);
    virtual ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;

private:
    std::string _target;
};