#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <sstream>

#define MAX_SIZE 8
#define GREEN_TXT "\033[32m"
#define RED_TXT "\033[31m"
#define RESET "\033[m"

class PhoneBook
{
public:
    PhoneBook();

    bool getValidInput(const std::string &prompt, std::string &input);
    bool getValidPhoneNumber(const std::string &prompt, std::string &input);
    bool handleUserInput(std::string userInput);
    void showInfo();
    void showError(const std::string &errorStr);
    bool add();
    bool validateInput(Contact &tempContacts, std::string &input);
    bool search();
    std::string truncStr(const std::string &str);
    void displayTable();
    void showContact();
    bool promptForIndex(std::string &inputStrContact, int &inputContact);
    void printContact(int inputContact);

private:
    Contact contacts[MAX_SIZE];
    int nextPosition;  // where should the next contact be saved, like array position
    int contactsCount; // how many valid contacts are currently stored
};

#endif