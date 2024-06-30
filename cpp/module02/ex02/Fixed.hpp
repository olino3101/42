#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
int nbrComma;
static const int fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed & other);
    Fixed(const int integer);
    Fixed(const float floating);
    ~Fixed(void);
    float toFloat( void ) const;
    int toInt( void ) const;
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    Fixed& operator=(const Fixed& other);
    bool operator==(const Fixed& other) const;
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;   
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;   
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed operator++(void);
    Fixed operator++(int);
    Fixed operator--(void);
    Fixed operator--(int);

    static Fixed min(Fixed &a, Fixed &b);
    static Fixed max(Fixed &a, Fixed &b);
    static Fixed min(const Fixed &a, const Fixed &b);
    static Fixed max(const Fixed &a, const Fixed &b);
};

    std::ostream& operator<<(std::ostream& os, Fixed const & Fixed);

#endif