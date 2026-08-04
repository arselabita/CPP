#ifndef WRONGDog_HPP
#define WRONGDog_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
    WrongDog();
    WrongDog(const WrongDog &original);
    WrongDog &operator=(const WrongDog &original);
    ~WrongDog();

    void setType(std::string type);
    void makeSound() const;

protected:
    std::string _type;
};

#endif