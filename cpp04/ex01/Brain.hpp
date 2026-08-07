#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
public:
    Brain();
    Brain(const Brain &original);
    Brain &operator=(const Brain &original);
    ~Brain();

    void setIdea(int index, std::string& ideas);
    const std::string& getIdea(int index) const;

private:
    std::string _ideas[100];
};

#endif