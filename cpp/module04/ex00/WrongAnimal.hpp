#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal & other);
    virtual ~WrongAnimal();
    virtual WrongAnimal& operator=(const WrongAnimal& other);
    virtual void makeSound() const;
    std::string getType() const;

protected:
    std::string type;
};
#endif