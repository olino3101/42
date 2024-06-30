#include "Zombie.hpp"

void Zombie::annouce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is dead" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie() {}
