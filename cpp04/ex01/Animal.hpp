#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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
    virtual void makeSound() const;
    
protected:
    std::string _type;
};
#endif