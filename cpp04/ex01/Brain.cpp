#include "Brain.hpp"

Brain::Brain()
{
    this->_ideas[100] = "nope";
    std::cout << "Brain Default Constructor Called" << std::endl;
}
Brain::Brain(const Brain &original)
{
    this->_ideas[100] = original._ideas[100];
    std::cout << "Brain Copy Constructor Called" << std::endl;
}
Brain &Brain::operator=(const Brain &original)
{
    if (this != &original)
        this->_ideas[100] = original._ideas[100];
    std::cout << "Brain Copy Operator Overload Called" << std::endl;
    return *this;
}
Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}