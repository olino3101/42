#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
class ClapTrap
{
protected:
    std::string name;
    unsigned int healtP;
    unsigned int energiP;
    unsigned int attackP;
public:
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    ClapTrap& operator=(const ClapTrap& other);
    ClapTrap(void);
    ClapTrap(const ClapTrap & other);
    ClapTrap(const std::string name);
    ClapTrap(const std::string name, unsigned int healtP, unsigned int energiP, unsigned int attackP);
    ~ClapTrap(void);

    unsigned int getAttackP() const;
    unsigned int getHealtP() const;
    unsigned int getEnergiP() const;

};
#endif