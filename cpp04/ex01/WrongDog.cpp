#include "WrongDog.hpp"

WrongDog::WrongDog()
{
    this->_type = "WrongDog";
    std::cout << "WrongDog Default Constructor Called" << std::endl;
}
WrongDog::WrongDog(const WrongDog &original) : WrongAnimal(original)
{
    std::cout << "WrongDog Copy Constructor Called" << std::endl;
}
WrongDog &WrongDog::operator=(const WrongDog &original)
{
    WrongAnimal::operator=(original);
    std::cout << "WrongDog Copy Operator Overload Called" << std::endl;
    return *this;
}
WrongDog::~WrongDog()
{
    std::cout << "WrongDog Destructor Called" << std::endl;
}
void WrongDog::setType(std::string type)
{
    this->_type = type;
}

void WrongDog::makeSound() const
{
    std::cout << "bee bee bee" << std::endl;
}
