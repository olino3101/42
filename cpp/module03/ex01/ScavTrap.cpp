#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
: ClapTrap("ScavTrap", 100, 50, 20) {
    std::cout << "Scavtrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
: ClapTrap(name, 100, 50, 20) {
    std::cout << "Scavtrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & other) {
    std::cout << "Scavtrap copy constructor called" << std::endl;
    healtP = other.healtP;
    energiP = other.energiP;
    attackP = other.attackP;
}
ScavTrap::~ScavTrap() {
    std::cout << "Scavtrap destructor called" << std::endl;
}
ScavTrap & ScavTrap::operator=(const ScavTrap & other)
{
    if (this != &other) {
        ClapTrap::operator= (other);
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (energiP == 0)
        return;
    energiP--;
    std::cout << name << " attacks " << target << " causing a lot of damage!! he caused";
    std::cout << attackP << " points of damage!"<< std::endl;
}

void ScavTrap::guardGate() {
    std::cout << " ScavTrap est entré en mode Gate keeper!!" << std::endl;
}