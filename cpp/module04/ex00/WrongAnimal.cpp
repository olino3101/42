#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("default"){
    std::cout << "default constructor called for animal" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal & other) {
    std::cout << "copy constructor called for animal" << std::endl;
}
WrongAnimal::~WrongAnimal() {
    std::cout << "destructor called for animal" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "<animal sound>" << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}
