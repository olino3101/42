#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    //const Animal* j = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    j = i;
    std::cout << j->getType() << std::endl;
    return 0;
}