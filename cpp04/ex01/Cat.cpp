#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "British Short Hair";
    try
    {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl; 
    }
    std::cout << "Cat Default Constructor Called" << std::endl;
}
Cat::Cat(const Cat &original) : Animal(original)
{
    try
    {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl; 
    }
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