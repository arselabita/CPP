#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>

class Base
{
public:
    Base();
    virtual ~Base();

};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);