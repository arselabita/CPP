#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default Constructor Called" << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::setType(std::string type)
{
    this->_type = type;
}
void Dog::makeSound()
{
    std::cout << "The dog barks" << std::endl;
}
