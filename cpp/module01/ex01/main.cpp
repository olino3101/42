#include "Zombie.hpp"

int main()
{
    Zombie *zombie = zombieHorde(3, "george");
    delete[] zombie;
}