#include "Cat.hpp"

Cat::Cat(){
    std::cout << "default constructor called for Cat" << std::endl;
    type = "cat";
}

Cat::Cat(const Cat & other) : Animal(other) {
    std::cout << "copy constructor called for Cat" << std::endl;
}

Cat::~Cat() {
    std::cout << "destructor called for Cat" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
        this->type = other.type;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "myaowwwwww" << std::endl;
}
