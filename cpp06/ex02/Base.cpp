#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::Base()
{
    std::cout << "Base default constructor called." << std::endl;
}
Base::~Base()
{
    std::cout << "Base destructor called." << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &refA = dynamic_cast<A &>(p);
        (void)refA;
        std::cout << "The type of the object REFERENCED is A." << std::endl;
        return;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        B &refB = dynamic_cast<B &>(p);
        (void)refB;
        std::cout << "The type of the object REFERENCED is B." << std::endl;
        return;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        C &refC = dynamic_cast<C &>(p);
        (void)refC;
        std::cout << "The type of the object REFERENCED is C." << std::endl;
        return;
    }
    catch (std::exception &e)
    {
    }
}

void identify(Base *p)
{
    if (p == NULL)
        return;
    A *ptrA = dynamic_cast<A *>(p);
    if (ptrA != NULL)
    {
        std::cout << "The type of the object POINTED is A." << std::endl;
        return;
    }
    B *ptrB = dynamic_cast<B *>(p);
    if (ptrB != NULL)
    {
        std::cout << "The type of the object POINTED is B." << std::endl;
        return;
    }
    C *ptrC = dynamic_cast<C *>(p);
    if (ptrC != NULL)
    {
        std::cout << "The type of the object POINTED is C." << std::endl;
        return;
    }
}

Base *generate(void)
{
    int choice = std::rand() % 3;
    switch (choice)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        std::cerr << "Failed to instantiate the class!" << std::endl;
        return NULL;
    }
}
