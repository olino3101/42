#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
int main()
{
    ClapTrap ninja("ninja");
    ScavTrap    scavtrap;
    ninja.attack("ScavTrap");

    scavtrap.takeDamage(0);

}