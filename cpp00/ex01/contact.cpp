#include "contact.hpp"

std::string Contact::getFirstName(){
    return firstName;
}
void Contact::setFirstName(std::string name){
    firstName = name;
}

std::string Contact::getLastName(){
    return lastName;
}
void Contact::setLastName(std::string surname){
    lastName = surname;
}

std::string Contact::getNickName(){
    return nickName;
}
void Contact::setNickName(std::string niName){
    nickName = niName;
}

std::string Contact::getDarkestSecret(){
    return darkestSecret;
}
void Contact::setDarkestSecret(std::string secret){
    darkestSecret = secret;
}

std::string Contact::getPhoneNumber()
{
    return phoneNumber;
}
void Contact::setPhoneNumber(std::string number){
    phoneNumber = number;
}