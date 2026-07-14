#include "phonebook.hpp"

void PhoneBook::setNextPosition(int position){
    nextPosition = position;
}
int PhoneBook::getNextPosition(){
    return nextPosition;
}

int PhoneBook::getNumOfContactsToDisplay(){
    return numOfContactsToDisplay;
}
void PhoneBook::setNumOfContactsToDisplay(int numContacts){
    numOfContactsToDisplay = numContacts;
}

void PhoneBook::add()
{
    std::string input;

    std::cout << "Enter first name: " << std::endl;
    std::getline(std::cin, input);
    contacts->setFirstName(input);

    std::cout << "Enter last name: " << std::endl;
    std::getline(std::cin, input);
    contacts->setLastName(input);

    std::cout << "Enter nick name: " << std::endl;
    std::getline(std::cin, input);
    contacts->setNickName(input);

    std::cout << "Enter darkest secret: " << std::endl;
    std::getline(std::cin, input);
    contacts->setDarkestSecret(input);

    std::cout << "Enter phone number: " << std::endl;
    std::getline(std::cin, input);
    contacts->setPhoneNumber(input);

    if (std::cin.eof() == true)
    {
        std::cout << "Careful you are using ctrl + D" << std::endl;
        exit(0);
    }
}
void PhoneBook::handleUserInput(std::string userInput)
{
    if (userInput == "ADD")
    {
        std::cout << "***Entering ADD*** " << std::endl;
        add();
    }
    else if (userInput == "SEARCH")
    {
        std::cout << "***Entering SEARCH***" << std::endl;

    }
    else if (userInput == "EXIT")
    {
        std::cout << "***Entering EXIT***" << std::endl;
    }
    return;
}
void PhoneBook::showInfo() {
    std::cout << "Enter a command: ADD, SEARCH, EXIT" << std::endl;
}