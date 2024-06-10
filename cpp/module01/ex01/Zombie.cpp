#include "Zombie.hpp"

void Zombie::annouce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(string name)
{   
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is dead" << std::endl;
}
