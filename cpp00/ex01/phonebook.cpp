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

bool PhoneBook::add()
{
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (input == "")
        return (false);
    contacts[nextPosition].setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (input == "")
        return (false);
    contacts[nextPosition].setLastName(input);

    std::cout << "Enter nick name: ";
    std::getline(std::cin, input);
    if (input == "")
        return (false);
    contacts[nextPosition].setNickName(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    if (input == "")
        return (false);
    contacts[nextPosition].setDarkestSecret(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    if (input == "")
        return (false);
    contacts[nextPosition].setPhoneNumber(input);

    nextPosition++;
    if (std::cin.eof() == true)
        return (false);
    return (true);
}
bool PhoneBook::handleUserInput(std::string userInput)
{
    if (userInput == "ADD")
    {
        std::cout << "***Entering ADD*** " << std::endl;
        if (add() == false)
            return (false);
        // std::cout << "First name: " << contacts[0].getFirstName() << " Last name: " << contacts[0].getLastName() 
        //     << " Nick name: " << contacts[0].getNickName() << " Darkest secret: " << contacts[0].getDarkestSecret() 
        //     << " Phone number: " << contacts[0].getPhoneNumber() << std::endl;
        
        // std::cout << "First name: " << contacts[1].getFirstName() << " Last name: " << contacts[1].getLastName() 
        //     << " Nick name: " << contacts[1].getNickName() << " Darkest secret: " << contacts[1].getDarkestSecret() 
        //     << " Phone number: " << contacts[1].getPhoneNumber() << std::endl;
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