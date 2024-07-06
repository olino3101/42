#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "Animal.hpp"

class WrongCat : virtual public Animal
{
public:
    WrongCat();
    WrongCat(const WrongCat & other);
    ~WrongCat();
    WrongCat& operator=(const WrongCat& other);
    void makeSound() const;
};

#endif
