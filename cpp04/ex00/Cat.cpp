#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default Constructor Called" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::setType(std::string type)
{
    this->_type = type;
}
void Cat::makeSound() const override
{
    std::cout << "The cat meaws" << std::endl;
}
