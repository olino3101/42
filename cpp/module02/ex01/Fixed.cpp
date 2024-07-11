#include "Fixed.hpp"

Fixed::Fixed(void) : nbrComma(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer) {
    std::cout << "Int constructor called" << std::endl;
    nbrComma = (integer << fractionalBits);
}

Fixed::Fixed(const Fixed & other) {
    std::cout << "Copy constructor called" << std::endl;
    nbrComma = other.nbrComma;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        nbrComma = other.nbrComma;
    }
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

Fixed::Fixed(const float nbr) {
    std::cout << "float constructor called" << std::endl;
    nbrComma = roundf(nbr * (1 << fractionalBits));
}

float Fixed::toFloat( void ) const {
    return (float)nbrComma / (1 << fractionalBits);
}

int Fixed::toInt( void ) const {
    return roundf(nbrComma) / (1 << fractionalBits);
}

std::ostream& operator<<(std::ostream& os, Fixed const & rhs) {
    os << rhs.toFloat();
    return os;
}