#pragma once

#include <iostream>
#include <iterator>
#include <deque>
#include <stack>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack() : std::stack<T>()
    {
    }
    MutantStack(const MutantStack &original) : std::stack<T>(original)
    {
        *this = original;
    }
    MutantStack &operator=(const MutantStack &original)
    {
        if (this != &original)
            std::stack<T>::operator=(original);
        return *this;
    }
    ~MutantStack()
    {
    }
    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }
};