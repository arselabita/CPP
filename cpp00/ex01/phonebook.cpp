#include "phonebook.hpp"

/// @brief constructor
PhoneBook::PhoneBook()
{
    nextPosition = 0;
    contactsCount = 0;
}

/// @brief  getters and setters
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

/// @brief  show info method
void PhoneBook::showInfo() {
    std::cout << "Welcome! Options: ADD, SEARCH, EXIT\n";
}

bool PhoneBook::getValidInput(const std::string& prompt, std::string& input){
    do {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return (false);
        input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());
        if (!input.empty())
            return (true);
        std::cout << "The field should'nt stay empty!!\n";
    } while (true);
}

bool PhoneBook::add(){
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

    if (contactsCount < MAX_SIZE)
        contactsCount++;

    nextPosition++;

    if (nextPosition == MAX_SIZE)
        nextPosition = 0;
    return (true);
}

std::string PhoneBook::truncStr(std::string str){
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::search(){
    std::cout << std::right;
    std::cout << "\n"
        << std::setw(10) << "Index" << " |"
        << std::setw(10) << "Firstname" << " |"
        << std::setw(10) << "Lastname" << " |"
        << std::setw(10) << "Nickname" << " |"
        << std::endl;
    std::cout << std::string(50, '-') << "\n";
    for (int i = 0; i < contactsCount; i++)
    {
        std::string name = contacts[i].getFirstName();
        std::string surname = contacts[i].getLastName();
        std::string nickname = contacts[i].getNickName();

        std::cout << std::setw(10) << (i) << " |"
            << std::setw(10) << truncStr(name) << " |"
            << std::setw(10) << truncStr(surname) << " |"
            << std::setw(10) << truncStr(nickname) << " |"
            << "\n";
    }
    std::cout << std::string(50, '-') << "\n";
}

bool PhoneBook::handleUserInput(std::string userInput)
{
    if (userInput == "ADD")
    {
        std::cout << "***Entering ADD*** " << std::endl;
        if (add() == false)
            return (false);
    }
    else if (userInput == "SEARCH")
    {
        std::cout << "***Entering SEARCH***" << std::endl;
        search();
    }
    else if (userInput == "EXIT")
    {
        std::cout << "***Entering EXIT***" << std::endl;
    }
    return (true);
}
