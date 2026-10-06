#pragma once

#include <string>
#include <iostream>

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
        _arr = new T[n]();
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
                this->_arr[i] = original._arr[i];
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
                    this->_arr[i] = original._arr[i];
            }
        }
        return *this;
    }
    ~Array()
    {
        delete[] _arr;
    }

    unsigned int size() const
    {
        return this->_num;
    }

private:
    T *_arr;
    unsigned int _num;
};