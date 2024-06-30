#include "Fixed.hpp"

Fixed::Fixed(void) : nbrComma(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed & other) {
    std::cout << "Copy constructor called" << std::endl;
    nbrComma = other.nbrComma;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    nbrComma = other.nbrComma;
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
     std::cout << "getRawBits member function called" << std::endl;
    return nbrComma;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    nbrComma = raw;
}