#include "Brain.hpp"

Brain::Brain()
{
    *(this->_ideas) = "nope";
    std::cout << "Brain Default Constructor Called" << std::endl;
}
Brain::Brain(const Brain &original)
{
    *(this->_ideas) = *(original._ideas);
    std::cout << "Brain Copy Constructor Called" << std::endl;
}
Brain &Brain::operator=(const Brain &original)
{
    if (this != &original)
        *(this->_ideas) = *(original._ideas);
    std::cout << "Brain Copy Operator Overload Called" << std::endl;
    return *this;
}
Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}

const std::string& Brain::getIdea() const{
    return *_ideas;
}

void Brain::setIdea(const std::string idea){
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = idea[i];
}