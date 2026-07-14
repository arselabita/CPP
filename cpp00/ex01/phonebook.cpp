#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    nextPosition = 0;
    contactsToDisplay = 0;
}
void PhoneBook::setNextPosition(int nextPosition){
    this->nextPosition = nextPosition;
}
int PhoneBook::getNextPosition(){
    return (nextPosition);
}

int PhoneBook::getNumOfContactsToDisplay(){
    return (contactsToDisplay);
}
void PhoneBook::setNumOfContactsToDisplay(int contactsToDisplay){
    this->contactsToDisplay = contactsToDisplay;
}

void PhoneBook::add()
{
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contacts[nextPosition].setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contacts[nextPosition].setLastName(input);

    std::cout << "Enter nick name: ";
    std::getline(std::cin, input);
    contacts[nextPosition].setNickName(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contacts[nextPosition].setDarkestSecret(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contacts[nextPosition].setPhoneNumber(input);
    nextPosition++;
    if (std::cin.eof() == true)
    {
        std::cout << "eof" << std::endl;
        exit(0);
    }
}
bool PhoneBook::handleUserInput(std::string userInput)
{
    if (userInput == "ADD")
    {
        std::cout << "***Entering ADD*** " << std::endl;
        add();
        return (true);
    }
    else if (userInput == "SEARCH")
    {
        std::cout << "***Entering SEARCH***" << std::endl;
        return (true);
    }
    else if (userInput == "EXIT")
    {
        std::cout << "***Entering EXIT***" << std::endl;
        return (false);
    }
    return (true);
}
void PhoneBook::showInfo() {
    std::cout << "Welcome! Options: ADD, SEARCH, EXIT\n";
}