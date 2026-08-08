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
    std::cout << BOLD << YELLOW << "\nTEST 3: DEEP COPY\n\n"
              << RESET;
    {
        Dog original;
        original.setIdea(0, "I like dogs!");

        std::cout << "\n--- Copy Constructor ---\n";

        Dog copy(original);

        std::cout << "Original: " << original.getIdea(0) << std::endl;
        std::cout << "Copy: " << copy.getIdea(0) << std::endl;

        original.setIdea(0, "I like cats!");

        std::cout << "After modifying original:\n";
        
        std::cout << "Original: " << original.getIdea(0) << std::endl;
        std::cout << "Copy: " << copy.getIdea(0) << std::endl;
    
        std::cout << "\n--- Assignment operator ---\n";
    
        Dog assigned;
        assigned = original;
    
        std::cout << "Assigned: " << assigned.getIdea(0) << std::endl;
        
        assigned.setIdea(0, "I dont like dogs!");

        std::cout << "After modifying original again:\n";

        std::cout << "Original: " << original.getIdea(0) << std::endl;
        std::cout << "Assignment: " << assigned.getIdea(0) << std::endl;
    }
    return 0;
}