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

ClapTrap::ClapTrap(void) : name("default") {}

ClapTrap::ClapTrap(const ClapTrap & other) {
    name = other.name;
    healtP = other.healtP;
    energiP = other.energiP;
    attackP = other.attackP;
}

ClapTrap::ClapTrap(const std::string name) : name(name) {}

ClapTrap::~ClapTrap(void) {}

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

// unsigned int ClapTrap::getAttackP() const {
//     return (attackP);
// }