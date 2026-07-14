#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>

#define MAX_SIZE 8

class PhoneBook {
    public:
        PhoneBook();

        // const Contact* getContactsArr();
        bool handleUserInput(std::string userInput);
        
        int getNextPosition();
        void setNextPosition(int nextPosition);
        
        int getNumOfContactsToDisplay();
        void setNumOfContactsToDisplay(int contactsToDisplay);
        
        bool add();
        void search();
        void showInfo();

    private:
        Contact contacts[MAX_SIZE];
        int nextPosition; // where should the next contact be saved, like array position 
        int contactsToDisplay; // how many valid contacts are currently stored
};


#endif