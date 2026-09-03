#pragma once

#include "AForm.hpp"
#include <iostream>

class Intern
{
public:
    Intern();
    Intern(const Intern &original);
    Intern &operator=(const Intern &original);
    ~Intern();

    AForm* makeForm(const std::string &nameOfForm, const std::string &targetOfForm);
};