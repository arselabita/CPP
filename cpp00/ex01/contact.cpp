#include "contact.hpp"

std::string Contact::getFirstName() const {
    return (firstName);
}
void Contact::setFirstName(std::string firstName){
    this->firstName = firstName;
}

std::string Contact::getLastName() const{
    return (lastName);
}
void Contact::setLastName(std::string lastName){
    this->lastName = lastName;
}

std::string Contact::getNickName() const{
    return (nickName);
}
void Contact::setNickName(std::string nickName){
    this->nickName = nickName;
}

std::string Contact::getDarkestSecret() const{
    return (darkestSecret);
}
void Contact::setDarkestSecret(std::string darkestSecret){
    this->darkestSecret = darkestSecret;
}

std::string Contact::getPhoneNumber() const{
    return (phoneNumber);
}
void Contact::setPhoneNumber(std::string phoneNumber){
    this->phoneNumber = phoneNumber;
}