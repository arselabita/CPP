#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template <class T>
class Array
{
public:
    Array()
    {
        this->_arr = NULL;
        this->_num = 0;
    }
    Array(unsigned int n)
    {
        this->_num = n;
        if (this->_num == 0)
            this->_arr = NULL;
        else
            _arr = new T[this->_num]();
    }
    Array(const Array &original)
    {
        this->_num = original._num;
        if (this->_num == 0)
            this->_arr = NULL;
        else
        {

            this->_arr = new T[this->_num]();
            for (unsigned int i = 0; i < this->_num; i++)
            {
                this->_arr[i] = original._arr[i];
            }
        }
    }
    Array &operator=(const Array &original)
    {
        if (this != &original)
        {
            delete[] this->_arr; // cleans up memory from the previous one
            this->_num = original._num;
            if (this->_num == 0)
                this->_arr = NULL;
            else
            {

                this->_arr = new T[this->_num]();
                for (unsigned int i = 0; i < this->_num; i++)
                {
                    this->_arr[i] = original._arr[i];
                }
            }
        }
        return *this;
    }
    ~Array()
    {
        delete[] this->_arr;
    }

    unsigned int size() const
    {
        return this->_num;
    }

    T &operator[](unsigned int i)
    {
        if (i >= this->_num)
            throw std::out_of_range("Index out of bounds!");
        return this->_arr[i];
    }

    const T &operator[](unsigned int i) const
    {
        if (i >= this->_num)
            throw std::out_of_range("Index out of bounds!");
        return this->_arr[i];
    }

private:
    T *_arr;
    unsigned int _num;
};