#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    Fixed(void); // Constructor

    Fixed(const int intValue);
    Fixed(const float floatValue);

    Fixed(const Fixed &original);            // Copy constructor
    Fixed &operator=(const Fixed &original); // Copy assignment operator

    ~Fixed(void); // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
    
    private:
    int _value;
    static const int _fractBits = 8;
};


#endif