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

int main()
{
    cout << "with new " << endl;
    Zombie *zombi = newZombie("zombie 1");
    zombi->annouce();
    delete zombi;

    cout << "with not new " << endl;
    randomChump("zombie 2");

    return 0;
}