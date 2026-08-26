#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nope"), _grade(0)
{
    std::cout << "Default constructor called\n";
}
Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
    std::cout << "Constructor called\n";
    _name = name;
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &original)
{
    std::cout << "Copy constructor called\n";
    this->_name = original._name;
    this->_grade = original._grade;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &original)
    {
        this->_name = original._name;
        this->_grade = original._grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName() const
{
    return _name;
}
const int Bureaucrat::getGrade() const
{
    return _grade;
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}