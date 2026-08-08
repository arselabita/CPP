#pragma once

#include <iostream>
#include <string>

class Animal
{
public:
    Animal();
    Animal(const Animal& original);
    Animal& operator=(const Animal& original);
    virtual ~Animal();

    const std::string getType() const;
    virtual void makeSound() const = 0;
    
protected:
    std::string _type;
};
