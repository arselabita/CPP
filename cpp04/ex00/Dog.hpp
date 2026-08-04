#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    ~Dog();

    void setType(std::string type);
    void makeSound() const override;
};
#endif