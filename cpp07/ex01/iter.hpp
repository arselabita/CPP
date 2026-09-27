#pragma once

#include <string>
#include <iostream>

template <typename T>
void iter(T *arrPtr, const T length, T (*operation)(T));