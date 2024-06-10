#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
using namespace std;
class Zombie
{

public:
    void annouce(void);
    void setName(string name);

    ~Zombie();
private:
    string name;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

# endif