#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

void identify(Base &p)
{
    try
    {
        A &refA = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::bad_cast &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try
    {
        B &refB = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::bad_cast &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try
    {
        C &refC = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::bad_cast &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void identify(Base *p)
{
    A *ptrA = dynamic_cast<A *>(p);
    if (ptrA != NULL)
    {
        std::cout << "The type of the object is A." << std::endl;
        return;
    }
    B *ptrB = dynamic_cast<B *>(p);
    if (ptrB != NULL)
    {
        std::cout << "The type of the object is B." << std::endl;
        return;
    }
    C *ptrC = dynamic_cast<C *>(p);
    if (ptrC != NULL)
    {
        std::cout << "The type of the object is C." << std::endl;
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

int main()
{
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Random object generator function:\n"
              << std::endl;
    {
        std::srand(std::time(NULL));

        Base *generatedObj = generate();
        if (generatedObj == NULL)
        {
            std::cerr << "Failed to generate object!" << std::endl;
            return 1;
        }
        delete generatedObj;
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Identify function (pointer):\n"
              << std::endl;
    {
        Base *ptrA = new A();
        identify(ptrA);
        std::cout << "\n";

        Base *ptrB = new B();
        identify(ptrB);
        std::cout << "\n";

        Base *ptrC = new C();
        identify(ptrC);
        std::cout << "\n";

        delete ptrA;
        delete ptrB;
        delete ptrC;
    }
    std::cout << "\n"
              << std::string(10, '-')
              << std::endl;
    std::cout << "Testing Identify function (reference):\n"
              << std::endl;
    {
        Base *ptrA = new A();
        identify(ptrA);
        std::cout << "\n";

        Base *ptrB = new B();
        identify(ptrB);
        std::cout << "\n";

        Base *ptrC = new C();
        identify(ptrC);
        std::cout << "\n";

        delete ptrA;
        delete ptrB;
        delete ptrC;
    }
    return 0;
}
