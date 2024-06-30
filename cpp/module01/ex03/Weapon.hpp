#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
public:

    const std::string &getType(void) const;
    void setType(std::string newtype);
    Weapon(std::string nameWeapon);
private:

    std::string type;
};
#endif