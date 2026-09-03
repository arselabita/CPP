#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signingGrade(1), _executeGrade(1), _sign(false)
{
}
AForm::AForm(const std::string &name, const int signingGrade, const int executingGrade) : _name(name), _signingGrade(signingGrade), _executeGrade(executingGrade), _sign(false)
{
    if (signingGrade < 1 || executingGrade < 1)
        throw GradeTooHighException();
    if (signingGrade > 150 || executingGrade > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm &original) : _name(original._name), _signingGrade(original._signingGrade), _executeGrade(original._executeGrade), _sign(original._sign)
{
}

AForm &AForm::operator=(const AForm &original)
{
    if (this != &original)
    {
        this->_sign = original._sign;
    }
    return *this;
}
AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
    return _name;
}
int AForm::getSignedGrade() const
{
    return _signingGrade;
}
int AForm::getExecuteGrade() const
{
    return _executeGrade;
}
bool AForm::getSign() const
{
    return _sign;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signingGrade)
        throw AForm::GradeTooLowException();
    this->_sign = true;
}
void AForm::execute(Bureaucrat const &executor) const
{
    if (this->getSign() == false)
        throw AForm::FormNotSigned();
    if(executor.getGrade() > this->_executeGrade)
        throw AForm::GradeTooLowException();
    executeForm();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << obj.getName() << ", AForm signed grade " << obj.getSignedGrade() << ", AForm execute grade " << obj.getExecuteGrade() << ", the AForm sign status " << (obj.getSign() ? "signed" : "unsigned") << std::endl;
    return out;
}
