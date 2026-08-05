#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    Brain *n = new Brain();
    Cat *b = new Brain();
    Dog *d = new Brain();
    delete j; // should not create a leak
    delete i;

    return 0;
}