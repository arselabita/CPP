#include "Animal.hpp"

Animal::Animal()
{
    this->_type = "nope";
    std::cout << "Animal Default Constructor Called" << std::endl;
}
Animal::Animal(const Animal &original)
{
    this->_type = original._type;
    std::cout << "Animal Copy Constructor Called" << std::endl;
}
Animal& Animal::operator=(const Animal &original)
{
    if (this != &original)
        this->_type = original._type;
    std::cout << "Animal Copy Operator Overload Called" << std::endl;
    return *this;
}
Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}
const std::string Animal::getType() const
{
    return _type;
}
void Animal::makeSound() const
{
    std::cout << "The animal makes a sound" << std::endl;
}