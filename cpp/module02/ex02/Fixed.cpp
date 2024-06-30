#include "Fixed.hpp"

Fixed::Fixed(void) : nbrComma(0) {
}

Fixed::Fixed(const int integer) { // maybe error
    nbrComma = (integer << fractionalBits);
}

Fixed::Fixed(const Fixed & other) {
    nbrComma = other.nbrComma;
}

Fixed::~Fixed(void) {
}

int Fixed::getRawBits( void ) const {
    return nbrComma;
}

void Fixed::setRawBits( int const raw ) {
    nbrComma = raw;
}

Fixed::Fixed(const float nbr) {
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

Fixed Fixed::min(Fixed &a, Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return (b);
    else
        return (a);
}

Fixed Fixed::max(Fixed &a, Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return (b);
    else
        return (a);
}

Fixed Fixed::min(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return (b);
    else
        return (a);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return (b);
    else
        return (a);
}