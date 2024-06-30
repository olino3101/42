#include "Weapon.hpp"

const std::string &Weapon::getType(void) const
{
    return this->type;
}

void Weapon::setType(std::string newtype)
{
    type = newtype;
}

Weapon::Weapon(std::string nameWeapon)
{
    this->type = nameWeapon;
}