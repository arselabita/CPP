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

template <typename T, typename container = std::deque<T>>
class MutantStack : public std::stack<T, container>
{
public:
    MutantStack() : std::stack<T, container>()
    {
    }
    MutantStack(const MutantStack &original) : std::stack<T, container>(original)
    {
    }
    MutantStack &operator=(const MutantStack &original)
    {
        if (this != &original)
            std::stack<T, container>::operator=(original);
        return *this;
    }
    ~MutantStack()
    {
    }

    typedef typename std::stack<T, container>::container_type::iterator iterator;
    typedef typename std::stack<T, container>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T, container>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T, container>::container_type::const_reverse_iterator const_reverse_iterator;

    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }
    const_iterator begin() const
    {
        return this->c.begin();
    }
    const_iterator end() const
    {
        return this->c.end();
    }
    reverse_iterator rbegin()
    {
        return this->c.rbegin();
    }
    reverse_iterator rend()
    {
        return this->c.rend();
    }
    const_reverse_iterator rbegin() const
    {
        return this->c.rbegin();
    }
    const_reverse_iterator rend() const
    {
        return this->c.rend();
    }
};