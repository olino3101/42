#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
public:
    Animal();
    Animal(const Animal & other);
    virtual ~Animal();
    virtual Animal& operator=(const Animal& other);
    virtual void makeSound() const = 0;
    std::string getType() const;
protected:
    std::string type;
};
#endif