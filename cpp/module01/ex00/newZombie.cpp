#include "Zombie.hpp"

Zombie* newZombie( string name )
{
    Zombie *zombie = new Zombie();
    zombie->is_malloc = true;
    zombie->setName(name);
    return (zombie);
}