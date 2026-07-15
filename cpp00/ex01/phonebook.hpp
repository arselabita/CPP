#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>

#define MAX_SIZE 8

class PhoneBook {
    public:
        PhoneBook();

        // const Contact* getContactsArr();
        bool getValidInput(const std::string& prompt, std::string& input);
        bool handleUserInput(std::string userInput);
    
        int getNextPosition();
        void setNextPosition(int nextPosition);
        
        int getContactsCount();
        void setContactsCount(int contactsCount);
        
        bool add();
        void search();
        void showInfo();
        std::string truncStr(std::string str);

    private:
        Contact contacts[MAX_SIZE];
        int nextPosition; // where should the next contact be saved, like array position 
        int contactsCount; // how many valid contacts are currently stored
};


#endif