#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat Default Constructor Called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &original)
{
    if (this != &original)
        WrongAnimal::operator=(original);
    std::cout << "WrongCat Copy Operator Overload Called" << std::endl;
    return *this;
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}
void WrongCat::makeSound() const
{
    std::cout << "aaa aaa aaa" << std::endl;
}
