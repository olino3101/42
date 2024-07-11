#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap
{
private:
    std::string name;
    unsigned int healtP = 10;
    unsigned int energiP = 10;
    unsigned int attackP = 0;
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    ClapTrap& operator=(const ClapTrap& other);
    ClapTrap(void);
    ClapTrap(const ClapTrap & other);
    ClapTrap(const std::string name);
    ~ClapTrap(void);

    //unsigned int getAttackP() const;
};
#endif