#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &original);
    Cat &operator=(const Cat &original);
    ~Cat();

    void makeSound() const;

private:
    Brain *smth;
};
#endif