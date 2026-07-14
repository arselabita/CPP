#include "phonebook.hpp"
#include "contact.hpp"

int main()
{
    PhoneBook phoneBook;

    phoneBook.showInfo();
    while (!std::cin.fail()) {
        std::string userInput;

        std::getline(std::cin, userInput);
        phoneBook.handleUserInput(userInput);
        if (std::cin.fail() == true || std::cin.eof() == true)
        {
            std::cerr << "Make sure you passed the right input." << std::endl;
            exit(0);
        }
        phoneBook.showInfo();
    }
    return (0);
}