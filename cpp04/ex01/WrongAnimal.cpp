#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->_type = "";
    std::cout << "WrongAnimal Default Constructor Called" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal &original)
{
    this->_type = original._type;
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &original)
{
    if (this != &original)
        this->_type = original._type;
    std::cout << "WrongAnimal Copy Operator Overload Called" << std::endl;
    return *this;
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal  Destructor Called" << std::endl;
}
const std::string WrongAnimal::getType() const
{
    return _type;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a sound" << std::endl;
}