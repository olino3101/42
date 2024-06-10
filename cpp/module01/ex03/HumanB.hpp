#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>
using namespace std;
class HumanB
{
public:

    void setWeapon(Weapon &newWeapon);
    void attack(void);
    HumanB(string name);
private:

    string _name;
    Weapon *_weapon;
};

#endif