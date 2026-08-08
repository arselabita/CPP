#pragma once

#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

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
