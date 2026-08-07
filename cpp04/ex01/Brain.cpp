#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "nope";
    std::cout << "Brain Default Constructor Called" << std::endl;
}
Brain::Brain(const Brain &original)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = original._ideas[i];
    std::cout << "Brain Copy Constructor Called" << std::endl;
}
Brain &Brain::operator=(const Brain &original)
{
    if (this != &original)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = original._ideas[i];
    }
    std::cout << "Brain Copy Operator Overload Called" << std::endl;
    return *this;
}
Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}

const std::string &Brain::getIdea(int index) const
{
   return _ideas[index];
}

void Brain::setIdea(int index, std::string& idea)
{
    this->_ideas[index] = idea;
}