#include "HumanB.hpp"

void HumanB::attack(void)
{
    if (this->_weapon != NULL && this->_weapon->getType() != "")
        cout << this->_name << " attacks with their " << this->_weapon->getType() << endl;
    else
        cout << this->_name << " has no weapon" << endl;
}

HumanB::HumanB(string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    this->_weapon = &newWeapon;
}