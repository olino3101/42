#include "Zombie.hpp"

Zombie* newZombie( string name )
{
    Zombie *zombie = new Zombie();
    zombie->setName(name);
    return (zombie);
}