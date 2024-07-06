#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "default constructor called for WrongCat" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat & other) : Animal(other) {
    std::cout << "copy constructor called for WrongCat" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "destructor called for WrongCat" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "wouf wouf" << std::endl;
}