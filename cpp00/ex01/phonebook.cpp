#include "phonebook.hpp"

/// @brief constructor
PhoneBook::PhoneBook()
{
    nextPosition = 0;
    contactsCount = 0;
}
/// @brief  show info method
void PhoneBook::showInfo()
{
    std::cout << GREEN_TXT << "\nWelcome!" << "\nOptions: ADD, SEARCH, EXIT\n"
              << RESET;
    std::cout << "\n"
              << std::string(50, '-') << "\n";
}
void PhoneBook::showError(const std::string &errorStr)
{
    std::cerr << RED_TXT << "\n"
              << errorStr << RESET;
    std::cout << "\n"
              << std::string(50, '-') << "\n";
}
bool PhoneBook::getValidInput(const std::string &prompt, std::string &input)
{
    do
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return false;
        if (!input.empty() && input.find_first_not_of(" \t") != std::string::npos)
            return true;
        showError("The field should'nt stay empty!!\n");
    } while (true);
}
bool PhoneBook::validateInput(Contact &tempContacts, std::string &input)
{
    if (!getValidInput("Enter first name: ", input))
        return false;
    tempContacts.setFirstName(input);

    if (!getValidInput("Enter last name: ", input))
        return false;
    tempContacts.setLastName(input);

    if (!getValidInput("Enter nick name: ", input))
        return false;
    tempContacts.setNickName(input);

    if (!getValidInput("Enter darkest secret: ", input))
        return false;
    tempContacts.setDarkestSecret(input);

    if (!getValidInput("Enter phone number: ", input))
        return false;
    tempContacts.setPhoneNumber(input);
    return true;
}
bool PhoneBook::add()
{
    std::string input;
    Contact tempContacts;

    if (!validateInput(tempContacts, input))
        return false;
    contacts[nextPosition] = tempContacts;
    if (contactsCount < MAX_SIZE)
        contactsCount++;
    nextPosition++;
    if (nextPosition == MAX_SIZE)
        nextPosition = 0;
    return true;
}

std::string PhoneBook::truncStr(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}
void PhoneBook::displayTable()
{
    std::cout << "\n"
              << std::setw(10) << "Index" << " |"
              << std::setw(10) << "Firstname" << " |"
              << std::setw(10) << "Lastname" << " |"
              << std::setw(10) << "Nickname" << " |"
              << std::endl;
    std::cout << std::string(50, '-') << "\n";

    for (int i = 0; i < contactsCount; i++)
    {

        std::cout << std::setw(10) << (i) << " |"
                  << std::setw(10) << truncStr(contacts[i].getFirstName()) << " |"
                  << std::setw(10) << truncStr(contacts[i].getLastName()) << " |"
                  << std::setw(10) << truncStr(contacts[i].getNickName()) << " |"
                  << "\n";
        std::cout << std::string(50, '-') << "\n";
    }
}

void PhoneBook::promptForIndex(std::string &inputStrContact, int &inputContact)
{
    while (true)
    {
        std::cout << "\nWhich contact do you want? ";
        if (!std::getline(std::cin, inputStrContact))
        {
            inputContact = -1;
            break;
        }
        if (inputStrContact.empty() || inputStrContact.find_first_not_of(" \t") == std::string::npos)
        {
            showError("Invalid input. Enter a number.\n");
            continue;
        }
        if (std::stringstream(inputStrContact) >> inputContact)
            break;
        showError("Invalid input. Enter a number.\n");
    }
}
void PhoneBook::printContact(int inputContact)
{
    std::cout << "\n"
              << "First name: " << contacts[inputContact].getFirstName()
              << "\n"
              << "Last name: " << contacts[inputContact].getLastName()
              << "\n"
              << "Nick name: " << contacts[inputContact].getNickName()
              << "\n"
              << "Darkest secret: " << contacts[inputContact].getDarkestSecret()
              << "\n"
              << "Phone number: " << contacts[inputContact].getPhoneNumber()
              << std::endl;
}
void PhoneBook::showContact()
{
    std::string inputStrContact;
    int inputContact;

    while (true)
    {
        promptForIndex(inputStrContact, inputContact);
        if (inputContact >= contactsCount || inputContact < 0)
            showError("Invalid index! Please enter a valid contact number! \n");
        else
        {
            printContact(inputContact);
            break;
        }
    }
}
bool PhoneBook::search()
{
    std::cout << std::right;

    if (contactsCount == 0)
        showError("PhoneBook is empty!\n");
    else
    {
        displayTable();
        showContact();
    }
    return true;
}

bool PhoneBook::handleUserInput(std::string userInput)
{
    if (userInput == "ADD")
    {
        std::cout << "***Entering ADD*** " << std::endl;
        if (!add())
            return false;
    }
    else if (userInput == "SEARCH")
    {
        std::cout << "***Entering SEARCH***" << std::endl;
        if (!search())
            return false;
    }
    else if (userInput == "EXIT")
    {
        std::cout << "***Entering EXIT***" << std::endl;
        std::cout << "Ciao!" << std::endl;
        exit(0);
    }
    return true;
}
