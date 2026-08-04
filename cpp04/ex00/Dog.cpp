#include "Dog.hpp"

Dog::Dog()
{
    this->_type = "Dog";
    std::cout << "Dog Default Constructor Called" << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &original)
{
    Animal::operator=(original);
    std::cout << "Dog Copy Operator Overload Called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "bark bark bark" << std::endl;
}
