#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original)
{
    this->_brain = new Brain();
    *this->_brain = *(original._brain);
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &original)
{
    if (this != &original)
    {
        Animal::operator=(original);
        *this->_brain = *(original._brain);
    }    
    std::cout << "Dog Copy Operator Overload Called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark bark bark" << std::endl;
}

void Dog::setIdea(int index, std::string& ideas)
{
    _brain->setIdea(index, ideas);
}
const std::string &Dog::getIdea(int index) const
{
    _brain->getIdea(index);
}