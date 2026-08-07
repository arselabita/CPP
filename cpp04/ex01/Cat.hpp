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
    void setIdea(int index, const std::string& ideas);
    const std::string& getIdea(int index) const;
private:
    Brain *_brain;
};
#endif