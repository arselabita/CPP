#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &original);
    Cat &operator=(const Cat &original);
    ~Cat();

    void makeSound() const;
};
