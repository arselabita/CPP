#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &original);
    Bureaucrat &operator=(const Bureaucrat &original);
    ~Bureaucrat();

    const std::string getName() const;
    const int getGrade() const;

    void incrementGrade();
    void decrementGrade();

private:
    const std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);