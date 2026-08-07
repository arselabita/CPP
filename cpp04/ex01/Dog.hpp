#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &original);
    Dog &operator=(const Dog &original);
    ~Dog();

    void makeSound() const;
    void setIdea(int index, std::string& ideas);
    const std::string& getIdea(int index) const;
private:
    Brain *_brain;
};
#endif