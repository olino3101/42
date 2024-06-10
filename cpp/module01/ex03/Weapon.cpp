#include "Weapon.hpp"

const string &Weapon::getType(void) const
{
    return this->type;
}

void Weapon::setType(string newtype)
{
    type = newtype;
}

Weapon::Weapon(string nameWeapon)
{
    this->type = nameWeapon;
}