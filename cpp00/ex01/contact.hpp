#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
    std::string getFirstName();
    void setFirstName(std::string name);

    std::string getLastName();
    void setLastName(std::string surname);

    std::string getNickName();
    void setNickName(std::string niName);

    std::string getDarkestSecret();
    void setDarkestSecret(std::string secret);

    std::string getPhoneNumber();
    void setPhoneNumber(std::string number);
    
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string darkestSecret;
    std::string phoneNumber;
};
#endif