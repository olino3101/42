#include "HumanA.hpp"

void HumanA::attack(void)
{
    cout << this->_name << " attacks with their " << this->_weapon.getType() << endl;
}
HumanA::HumanA(string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}