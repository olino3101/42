#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
long long int nbrComma;
static const int fractionalBits = 8;

public:
    Fixed(void);
    Fixed(const Fixed & other);
    Fixed& operator=(const Fixed& other);
    ~Fixed(void);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};
#endif