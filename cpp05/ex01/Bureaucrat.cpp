#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original) : _name(original._name), _grade(original._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
    if (this != &original)
    {
        this->_grade = original._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}
const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade += 1;
}
void Bureaucrat::signForm(Form &form)
{
    try
    {
       form.beSigned(*this);
       std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (const Form::GradeTooLowException &e)
    {
        std::cerr << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return out;
}