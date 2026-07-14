#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <string>

#define MAX_SIZE 8

class PhoneBook {
    public:
        void showInfo();
        void handleUserInput(std::string userInput);

        const Contact* getContactsArr();

        int getNextPosition();
        void setNextPosition(int position);

        int getNumOfContactsToDisplay();
        void setNumOfContactsToDisplay(int numContacts);
        
        void add();
        void search();

    private:
        Contact contacts[MAX_SIZE];
        int nextPosition; // where should the next contact be saved
        int numOfContactsToDisplay; // how many valid contacts can search display
};


#endif