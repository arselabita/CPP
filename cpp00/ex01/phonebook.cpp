#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    nextPosition = 0;
    contactsCount = 0;
}
void PhoneBook::setNextPosition(int nextPosition){
    this->nextPosition = nextPosition;
}
int PhoneBook::getNextPosition(){
    return (nextPosition);
}

int PhoneBook::getContactsCount(){
    return (contactsCount);
}
void PhoneBook::setContactsCount(int contactsCount){
    this->contactsCount = contactsCount;
}

bool PhoneBook::getValidInput(const std::string& prompt, std::string& input){
    do {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return (false);
        if (!input.empty())
            return (true);
        std::cout << "The field should'nt stay empty!!\n";
    } while (true);
    return (true);
}

bool PhoneBook::add()
{
    std::string input;
    Contact tempContacts;

    if (!getValidInput("Enter first name: ", input))
        return (false);
    tempContacts.setFirstName(input);

    if (!getValidInput("Enter last name: ", input))
        return (false);
    tempContacts.setLastName(input);

    if (!getValidInput("Enter nick name: ", input))
        return (false);
    tempContacts.setNickName(input);

    if (!getValidInput("Enter darkest secret: ", input))
        return (false);
    tempContacts.setDarkestSecret(input);

    if (!getValidInput("Enter phone number: ", input))
        return (false);
    tempContacts.setPhoneNumber(input);

    contacts[nextPosition] = tempContacts;

    nextPosition++;
    contactsCount++;

    if (nextPosition == MAX_SIZE)
        nextPosition = 0;
    return (true);
}
bool PhoneBook::handleUserInput(std::string userInput)
{
    if (userInput == "ADD")
    {
        std::cout << "***Entering ADD*** " << std::endl;
        if (add() == false)
            return (false);
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