#pragma once

#include <list>
#include <deque>
#include <vector>
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

class Error
{
public:
    class NotFoundElement : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Element not found!";
        }
    };
};

template <typename T>
typename T::iterator easyfind(T &smth, int n)
{

    typename T::iterator it = std::find(smth.begin(), smth.end(), n);
    if (it == smth.end())
        throw Error::NotFoundElement();
    std::cout << GREEN << "\nElement found!" << RESET << std::endl;
    return it;
}