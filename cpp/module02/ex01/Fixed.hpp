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
    float toFloat( void ) const;
    int toInt( void ) const;
    Fixed& operator=(const Fixed& other);
    ~Fixed(void);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

    std::ostream& operator<<(std::ostream& os, Fixed const & Fixed);

#endif