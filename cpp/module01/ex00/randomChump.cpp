#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie zombie;
    zombie.is_malloc = false;
    zombie.setName(name);
    zombie.annouce();
}