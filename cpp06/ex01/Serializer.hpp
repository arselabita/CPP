#pragma once

#include <iostream>
#include <string>

class Serializer
{
public:
    uintptr_t serialize(Data *ptr);
    Data *deserialize(uintptr_t raw);

private:
};