#include "ClapTrap.hpp"

int main()
{
    ClapTrap ninja("ninja");
    ClapTrap soldat("soldat");

    ninja.attack("soldat");

    soldat.takeDamage(2);

}