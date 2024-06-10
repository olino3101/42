#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
class HumanA
{
public:

    void attack(void);
    HumanA(string name, Weapon &weapon);
private:
    string _name;
    Weapon& _weapon;
};

#endif