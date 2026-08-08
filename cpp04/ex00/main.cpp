#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << BOLD << CYAN << "\nTEST 1: POLYMORPHISM\n\n"
              << RESET;
    {
        const Animal *meta = new Animal();
        const Animal *cat = new Cat();
        const Animal *dog = new Dog();

        std::cout << "Cat type: " << cat->getType() << " " << std::endl;
        std::cout << "Dog type: " << dog->getType() << " " << std::endl;

        cat->makeSound();
        dog->makeSound();
        meta->makeSound();

        delete (dog);
        delete (cat);
        delete (meta);
    }
    std::cout << BOLD << GREEN << "\nTEST 2: WRONG POLYMORPHISM\n\n"
              << RESET;
    {
        const WrongAnimal *animal = new WrongAnimal();
        const WrongAnimal *cat = new WrongCat();

        std::cout << "Wrong cat type: " << cat->getType() << " " << std::endl;

        animal->makeSound();
        cat->makeSound();

        delete (cat);
        delete (animal);
    }
    return 0;
}