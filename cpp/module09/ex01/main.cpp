#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "wrong number of args" << std::endl;
        return 1;
    }
    if (argv[1][0] == '\0') {
        std::cout << "nothing as input" << std::endl;
        return 1;
    }
    RPN rpn(argv);
    rpn.calculate();
    return 0;
}