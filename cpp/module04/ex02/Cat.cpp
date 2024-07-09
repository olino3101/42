#include "Cat.hpp"

Cat::Cat(){
    brain = new Brain();
    std::cout << "default constructor called for Cat" << std::endl;
    type = "cat";
}

Cat::Cat(const Cat & other) : Animal(other) {
    std::cout << "copy constructor called for Cat" << std::endl;
    this->brain = other.brain;
}

Cat::~Cat() {
    std::cout << "destructor called for Cat" << std::endl;
    delete this->brain;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = other.brain;
    }   
    return *this;
}

void Cat::makeSound() const {
    std::cout << "myaowwwwww" << std::endl;
}
