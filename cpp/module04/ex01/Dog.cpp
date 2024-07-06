#include "Dog.hpp"

Dog::Dog() {
    brain = new Brain();
    type = "Dog";
    std::cout << "default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog & other) : Animal(other) {
    std::cout << "copy constructor called for Dog" << std::endl;
    this->brain = other.brain;
}

Dog::~Dog() {
    std::cout << "destructor called for Dog" << std::endl;
    delete this->brain;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = other.brain;
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "wouf wouf or bark bark" << std::endl;
}
