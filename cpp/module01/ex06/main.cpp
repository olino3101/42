#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl him;

    if (argc != 2)
    {
        std::cout << "no complaining" << std::endl;
        return 0;
    }
    him.complain(argv[1]);
}