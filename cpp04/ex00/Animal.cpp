#include "Animal.hpp"

Animal::Animal()
{
    this->_type = "nope";
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "The animal makes a sound" << std::endl;
}

std::string Animal::getType() const
{
    return _type;
}