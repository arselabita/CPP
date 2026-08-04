#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"


int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();

std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

const WrongAnimal* s = new WrongCat();
const WrongCat* w = new WrongCat();
const WrongDog* z = new WrongDog();

std::cout << w->getType() << " " << std::endl;
std::cout << z->getType() << " " << std::endl;
z->makeSound();
w->makeSound();
s->makeSound();

delete (meta);
delete (i);
delete (j);
delete (w);
delete (z);
delete (s);
return 0;
}