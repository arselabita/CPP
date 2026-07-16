#include "phonebook.hpp"
#include "contact.hpp"

int main()
{
    PhoneBook phoneBook;

    phoneBook.showInfo();
    while (!std::cin.fail())
    {
        std::string userInput;

        std::getline(std::cin, userInput);
        if (phoneBook.handleUserInput(userInput) == false)
        {
            std::cout << "Bye!\n";
            std::cin.clear();
            break;
        }
        if (std::cin.fail() == true || std::cin.eof() == true)
        {
            std::cerr << "Make sure you passed the right input." << std::endl;
            std::cin.clear();
            break;
        }
        std::cin.clear();
        phoneBook.showInfo();
    }
    return 0;
}