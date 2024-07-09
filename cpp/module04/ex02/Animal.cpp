#include "Animal.hpp"

Animal::Animal() : type("default"){
    std::cout << "default constructor called for animal" << std::endl;
}

Animal::Animal(const Animal & other) {
    std::cout << "copy constructor called for animal" << std::endl;
}

Animal::~Animal() {
    std::cout << "destructor called for animal" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "<animal sound>" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
