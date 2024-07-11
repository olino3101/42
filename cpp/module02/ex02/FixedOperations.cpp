#include "Fixed.hpp"

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        nbrComma = other.nbrComma;
    }
    nbrComma = other.nbrComma;
    return *this;
}

bool    Fixed::operator==(const Fixed& other) const {
    return (this->nbrComma == other.nbrComma);
}

bool Fixed::operator>(const Fixed& other) const {
    return (this->nbrComma > other.nbrComma);
}

bool Fixed::operator<(const Fixed& other) const {
    return (this->nbrComma < other.nbrComma);
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->nbrComma >= other.nbrComma);
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->nbrComma <= other.nbrComma);
}

bool Fixed::operator!=(const Fixed& other) const {
    return (this->nbrComma != other.nbrComma);
}

Fixed Fixed::operator+(const Fixed& other) const {
    Fixed newFixed(*this);
    newFixed.setRawBits(this->getRawBits() + other.getRawBits());
    return newFixed;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed newFixed(*this);
    newFixed.setRawBits(this->getRawBits() - other.getRawBits());
    return newFixed;
}

Fixed Fixed::operator*(const Fixed& other) const {
    
	Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)other.getRawBits());
	val.setRawBits((tmp1 * tmp2) / (1 << Fixed::fractionalBits));
	return (val);
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed val(*this);
	long tmp1, tmp2;

	tmp1 = ((long)this->getRawBits());
	tmp2 = ((long)other.getRawBits());
	val.setRawBits((tmp1 / tmp2) / (1 << Fixed::fractionalBits));
	return (val);
}

Fixed Fixed::operator++(void) {
    this->nbrComma++;
	return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    operator++();
    return (*this);
}

Fixed Fixed::operator--(void) {
    this->nbrComma--;
	return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    operator--();
    return (*this);
}
