#include "FragTrap.hpp"

FragTrap::FragTrap() 
: ClapTrap("FragTrap", 100, 100, 30) {
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) 
: ClapTrap(name, 100, 100, 30) {
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap & other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap & other) {
    if (this != &other) {
        ClapTrap::operator= (other);
    }
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (energiP == 0)
        return;
    energiP--;
    std::cout << "The FragTrap" << name << " attacks " << target << " causing a lot of damage!! he caused";
    std::cout << attackP << " points of damage!"<< std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::string highFive;
    std::cout << name << " Gives an High five! Press y to give an high five" << std::endl;
    std::cin >> highFive;
    if (highFive == "y")
        std::cout << " Youpi you gave the high five back! " << std::endl;

}