#include "Brain.hpp"

Brain::Brain() {
    std::cout << "default constructor called for Brain" << std::endl;
}
Brain::Brain(const Brain & other) {
    std::cout << "copy constructor called for Brain" << std::endl;
}
Brain::~Brain() {
    std::cout << "destructor called for Brain" << std::endl;
}
Brain& Brain::operator=(const Brain& other) {
    if (this != &other)
    {
        std::copy(std::begin(ideas), std::end(ideas), std::begin(this->ideas));
    }
    return *this;
}
