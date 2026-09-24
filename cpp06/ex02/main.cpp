#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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
        std::cout << "\nPrinting the object pointed to: " << std::endl;
        identify(generatedObj);
        std::cout << "\nPrinting the object referenced to: " << std::endl;
        identify(*generatedObj);
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
        identify(*ptrA);
        std::cout << "\n";

        Base *ptrB = new B();
        identify(*ptrB);
        std::cout << "\n";

        Base *ptrC = new C();
        identify(*ptrC);
        std::cout << "\n";

        delete ptrA;
        delete ptrB;
        delete ptrC;
    }
    return 0;
}
