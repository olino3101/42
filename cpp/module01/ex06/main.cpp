#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl him;

    if (argc != 2)
    {
        cout << "no complaining" << endl;
        return 0;
    }
        
    him.complain(argv[1]);
}