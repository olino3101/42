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

Zombie* zombieHorde( int N, std::string name );

# endif