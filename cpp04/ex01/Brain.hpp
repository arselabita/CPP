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

    void setIdea(const std::string ideas);
    const std::string& getIdea() const;

private:
    std::string _ideas[100];
};

#endif