#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signingGrade(1), _executeGrade(1), _sign(false)
{
}
Form::Form(const std::string &name, const int signingGrade, const int executingGrade, bool sign) : _name(name), _signingGrade(signingGrade), _executeGrade(executingGrade), _sign(sign)
{
    if (signingGrade < 1 || executingGrade < 1)
        throw GradeTooHighException();
    if (signingGrade > 150 || executingGrade > 150)
        throw GradeTooLowException();
}
Form::Form(const Form &original) : _name(original._name), _signingGrade(original._signingGrade), _executeGrade(original._executeGrade), _sign(original._sign)
{
}

Form &Form::operator=(const Form &original)
{
    if (this != &original)
    {
        this->_sign = original._sign;
    }
    return *this;
}
Form::~Form()
{
}
const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}
const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}
const std::string &Form::getName() const
{
    return _name;
}
int Form::getSignedGrade() const
{
    return _signingGrade;
}
int Form::getExecuteGrade() const
{
    return _executeGrade;
}
bool Form::getSign() const
{
    return _sign;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signingGrade)
        throw Form::GradeTooLowException();
    this->_sign = true;
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << obj.getName() << ", form signed grade " << obj.getSignedGrade() << ", form execute grade " << obj.getExecuteGrade() << ", the form sign status " <<(obj.getSign() ? "signed" : "unsigned")  << std::endl;
    return out;
}
