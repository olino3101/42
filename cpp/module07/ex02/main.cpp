#include "Array.hpp"

int main(void)
{
    Array<int> a(10);
    Array<int> vide;

    
    try
    {
        a[6] = 8;
        std::cout << a[6] << std::endl;
        std::cout << a[3] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
	std::cout << a.size() << std::endl;
    return (0); 
}