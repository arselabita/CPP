#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string; // declaring a pointer
    std::string& stringREF = string;

    std::cout << "Memory address of 'string': " << &string << std::endl;
    std::cout << "Memory address of 'stringPTR': " << stringPTR << std::endl;
    std::cout << "Memory address of 'stringREF': " << &stringREF << std::endl;

    std::cout << "The value of 'string': " << string << std::endl;
    std::cout << "The value pointed to by 'stringPTR': " << *stringPTR << std::endl;
    std::cout << "The value pointed to by 'stringREF': " << stringREF << std::endl;
	return EXIT_SUCCESS;
}