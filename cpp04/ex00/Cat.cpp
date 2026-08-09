#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat";
    std::cout << "Cat Default Constructor Called" << std::endl;
}
Cat::Cat(const Cat &original) : Animal(original)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
}
Cat& Cat::operator=(const Cat &original)
{
    if (this != &original)
        Animal::operator=(original);
    std::cout << "Cat Copy Operator Overload Called" << std::endl;
    return *this;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meaw Meaw Meaw" << std::endl;
}
