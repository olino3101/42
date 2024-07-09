#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
    public:
    FragTrap();
    FragTrap(const FragTrap & other);
    ~FragTrap();
    FragTrap(std::string name);
    FragTrap & operator=(const FragTrap & other);

    void attack(const std::string& target);
    void guardGate();
    void highFivesGuys(void);
};
#endif