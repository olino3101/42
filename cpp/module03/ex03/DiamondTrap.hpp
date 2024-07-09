#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public virtual ScavTrap : public virtual FragTrap
{
    public:
    DiamondTrap();
    DiamondTrap(const DiamondTrap & other);
    ~DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap & operator=(const DiamondTrap & other);
    private:
    std::string name;
};
#endif;