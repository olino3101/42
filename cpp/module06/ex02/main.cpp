#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void) {
    Base *base;
    std::srand(static_cast<unsigned int>(std::time(0)));
    int rn = std::rand() % 3 + 1;
    switch (rn) {
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
                (void)dynamic_cast<A &>(p);
                    std::cout << "Class A" << std::endl;
            }
            else if (i == 1)
            {
                (void)dynamic_cast<B &>(p);
                std::cout << "Class B" << std::endl;
            }
            else if (i == 2)
            {
                (void)dynamic_cast<C &>(p);
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