#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <stdexcept>

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

    // comparison
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // arithmetic add, decrement, multiply, divide
    Fixed operator*(const Fixed &other) const;
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Increment, decrement, post increment, post decrement
    Fixed &operator++();   // prefix increment
    Fixed operator++(int); // postfix increment
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed& min(Fixed& num1, Fixed& num2);
    static const Fixed& min(const Fixed& num1, const Fixed& num2);
    static Fixed& max(Fixed& num1, Fixed& num2);
    static const Fixed& max(const Fixed& num1, const Fixed& num2);

    friend std::ostream &operator<<(std::ostream &os, const Fixed &obj);

private:
    int _value;
    static const int _fractBits = 8;
};

#endif