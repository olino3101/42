#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
using namespace std;

class Weapon
{
public:

    const string &getType(void) const;
    void setType(string newtype);
    Weapon(string nameWeapon);
private:

    string type;
};
#endif