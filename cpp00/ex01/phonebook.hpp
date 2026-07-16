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

class PhoneBook
{
public:
    PhoneBook();

    bool getValidInput(const std::string &prompt, std::string &input);
    bool handleUserInput(std::string userInput);
    void showInfo();
    bool add();
    bool validateInput(Contact &tempContacts, std::string &input);
    bool search();
    std::string truncStr(const std::string &str);
    void displayTable();
    void showContact();
    void promptForIndex(std::string &inputStrContact, int &inputContact);
    void printContact(int inputContact);
    void exit();

private:
    Contact contacts[MAX_SIZE];
    int nextPosition;  // where should the next contact be saved, like array position
    int contactsCount; // how many valid contacts are currently stored
};

#endif