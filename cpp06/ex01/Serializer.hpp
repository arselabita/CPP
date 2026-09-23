#pragma once

#include <iostream>
#include <string>
#include <cstdint>
#include "Data.hpp"

class Serializer
{
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

private:
    Serializer();
    Serializer(const Serializer &original);
    Serializer &operator=(const Serializer &original);
    ~Serializer();
};