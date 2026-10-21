#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

#include <list>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <exception>

class Span
{
public:
    Span();
    Span(unsigned int n);
    Span(const Span &original);
    Span &operator=(const Span &original);
    ~Span();

    class SpanFullException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Span capacity has been exceeded.";
        }
    };

    class EmptySpanException : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Not enough elements to calculate a span (minimum required 2).";
        }
    };

    void addNumber(unsigned int num);
    template <typename T>
    void addNumberOnRange(T start, T end)
    {
        unsigned int num_to_add = std::distance(start, end);
        if (this->_v.size() + num_to_add > this->_maxN)
            throw Span::SpanFullException();
        this->_v.insert(_v.end(), start, end);
    }
    unsigned int shortestSpan();
    unsigned int longestSpan();

private:
    unsigned int _maxN;
    std::vector<unsigned int> _v;
};
