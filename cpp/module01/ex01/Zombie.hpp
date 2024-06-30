#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

public:
    void annouce(void);

	Zombie();
	Zombie(std::string name);
    ~Zombie();
private:
    std::string name;
};

Zombie* zombieHorde( int N, std::string name );

# endif