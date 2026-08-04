#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &original);
    WrongAnimal &operator=(const WrongAnimal &original);
    virtual ~WrongAnimal();

    const std::string getType() const;
    virtual void makeSound() const;

protected:
    std::string _type;
};

#endif