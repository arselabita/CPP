#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    std::string getFirstName() const;
    void setFirstName(std::string firstName);

    std::string getLastName() const;
    void setLastName(std::string lastName);

    std::string getNickName() const;
    void setNickName(std::string nickName);

    std::string getDarkestSecret() const;
    void setDarkestSecret(std::string darkestSecret);

    std::string getPhoneNumber() const;
    void setPhoneNumber(std::string phoneNumber);
    
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;
};
#endif