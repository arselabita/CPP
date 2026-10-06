#pragma once

#include <string>
#include <iostream>

template <class T>
class Array
{
public:
    Array()
    {
    }
    Array(unsigned int n)
    {
        this->_num = n;
    }
    Array(const Array &original)
    {
        this->_num = original._num;
    }
    Array &operator=(const Array &original)
    {
        if (this != &original)
        {
            this->_num = original._num;
        }
        return *this;
    }
    ~Array()
    {
    }

    
    void size()
    {
        for (int i = 0; i < _num; i++)
            std::count << "the number of elements in the array is: " << i << std::endl;
    }

private:
    unsigned int _num;
};