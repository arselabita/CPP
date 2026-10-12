#pragma once

#include <string>
#include <iostream>

template <typename T>
void iter(T *arrPtr, const std::size_t &length, void (*funct)(T &))
{
    if (!arrPtr || !funct)
        return ;
    for (size_t i = 0; i < length; i++)
        funct(arrPtr[i]);
}
template <typename T>
void iter(const T *arrPtr, const std::size_t &length, void (*funct)(const T &))
{
    if (!arrPtr || !funct)
        return ;
    for (size_t i = 0; i < length; i++)
        funct(arrPtr[i]);
}
template <typename T>
void add(T &num)
{
    num += num;
}
template <typename T>
void multiplication(T &num)
{
    num *= num;
}
template <typename T>
void print(const T &str)
{
    std::cout << "My name is: " << str << std::endl;
}
