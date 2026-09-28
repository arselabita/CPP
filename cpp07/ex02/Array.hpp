#pragma once

#define MAX_VAL 750

#include <string>
#include <iostream>
#include <ctime>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array &original);
    Array &operator=(const Array &original);
    ~Array();
};