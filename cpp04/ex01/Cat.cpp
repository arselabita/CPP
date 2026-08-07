#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat Default Constructor Called" << std::endl;
}
Cat::Cat(const Cat &original) : Animal(original)
{
    this->_brain = new Brain();
    *(this->_brain) = *(original._brain);
    std::cout << "Cat Copy Constructor Called" << std::endl;
}
Cat &Cat::operator=(const Cat &original)
{
    if (this != &original)
    {
        Animal::operator=(original);
        *(this->_brain) = *(original._brain);
    }
    std::cout << "Cat Copy Operator Overload Called" << std::endl;
    return *this;
}
Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat Destructor Called" << std::endl;
}
void Cat::makeSound() const
{
    std::cout << "Meaw Meaw Meaw" << std::endl;
}

void Cat::setIdea(int index, const std::string &ideas)
{
    _brain->setIdea(index, ideas);
}
const std::string &Cat::getIdea(int index) const
{
    return _brain->getIdea(index);
}