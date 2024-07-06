#include "Dog.hpp"

Dog::Dog() {
    type = "Dog";
    std::cout << "default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog & other) : Animal(other) {
    std::cout << "copy constructor called for Dog" << std::endl;
}

Dog::~Dog() {
    std::cout << "destructor called for Dog" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "wouf wouf or bark bark" << std::endl;
}
