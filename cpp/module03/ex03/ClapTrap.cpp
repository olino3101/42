#include "ClapTrap.hpp"

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        name = other.name;
        healtP = other.healtP;
        energiP = other.energiP;
        attackP = other.attackP;
    }
    return *this;
}

ClapTrap::ClapTrap(const std::string name, unsigned int healtP, unsigned int energiP, unsigned int attackP)
    : name(name), healtP(healtP), energiP(energiP), attackP(attackP) {
        std::cout << "ClapTrap constructor called" << std::endl;
    }

ClapTrap::ClapTrap(void) : name("default"), healtP(10), energiP(10), attackP(0){
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    name = other.name;
    healtP = other.healtP;
    energiP = other.energiP;
    attackP = other.attackP;
}

ClapTrap::ClapTrap(const std::string name)
    : name(name), healtP(10), energiP(10), attackP(0){
        std::cout << "ClapTrap constructor called" << std::endl;
    }

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energiP == 0)
        return;
    energiP--;
    std::cout << "ClapTrap " << name << " attacks " << target << " causing ";
    std::cout << attackP << " points of damage!"<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (healtP == 0)
    {
        std::cout << "ClapTrap " << name << " is dead " << std::endl;
        return ;
    }
    if (healtP - amount > 0)
        healtP -= amount;
    else
    {
        if (healtP != 0)
            std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
        healtP = 0;
        std::cout << "ClapTrap " << name << " is dead " << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energiP == 0)
        return;
    energiP--;
    healtP += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " health points!" << std::endl;
}
