#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <random>
#include <type_traits>

Base * generate(void) {
    Base *base;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 3);
    int random = dis(gen);
    switch (random) {
        case 1:
            base = new A;
            break;
        case 2:
            base = new B;
            break;
        case 3:
            base = new C;
            break;
    }
    return base;
}

void identify(Base* p) {
    if (dynamic_cast<A *>(p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Class B" << std::endl;
    else
        std::cout << "Class C" << std::endl;
}

void identify(Base& p) {
    int i = 0;

    while (i < 3)
    {
        try 
        {
            if (i == 0)
            {
                dynamic_cast<A &>(p);
                    std::cout << "Class A" << std::endl;
            }
            else if (i == 1)
            {
                dynamic_cast<B &>(p);
                std::cout << "Class B" << std::endl;
            }
            else if (i == 2)
            {
                dynamic_cast<C &>(p);
                std::cout << "Class C" << std::endl;
            }
        }
        catch (std::exception &e){
            i++;
            continue ;
        }
        break ;
    }
}

int main()
{
    Base *random =  generate(); 
    identify(random);
    identify(*random);
    delete random;
    return 0;
}