#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &original);
    Bureaucrat &operator=(const Bureaucrat &original);
    ~Bureaucrat();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    /// new added for the Form Class
    void signForm(Form &form);

private:
    const std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);