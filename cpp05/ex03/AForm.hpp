#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{

public:
    AForm();
    AForm(const std::string &name, const int signingGrade, const int executingGrade);
    AForm(const AForm &original);
    AForm &operator=(const AForm &original);
    virtual ~AForm();

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
    class FormNotSigned : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    const std::string &getName() const;
    int getSignedGrade() const;
    int getExecuteGrade() const;
    bool getSign() const;

    void beSigned(const Bureaucrat &bureaucrat);

    void executeForms(); // implement a function to execute the form’s action in the concrete classes
    virtual void execute(Bureaucrat const & executor) const = 0;

private:
    const std::string _name;
    const int _signingGrade;
    const int _executeGrade;
    bool _sign;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);
