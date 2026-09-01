#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{

public:
    Form();
    Form(const std::string &name, const int signingGrade, const int executingGrade, bool sign);
    Form(const Form &original);
    Form &operator=(const Form &original);
    ~Form();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return "Grade too high!"; }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw() { return "Grade too low!"; }
    };

    const std::string &getName() const;
    int getSignedGrade() const;
    int getExecuteGrade() const;
    bool getSign() const;

    void beSigned(const Bureaucrat &bureaucrat);

private:
    const std::string _name;
    const int _signingGrade;
    const int _executeGrade;
    bool _sign;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);
