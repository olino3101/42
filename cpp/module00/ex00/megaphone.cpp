#include <iostream>

int strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; j < (int)strlen(argv[i]); j++)
                std::cout << (char)std::toupper(argv[i][j]);
            std::cout << std::endl;
        }
    }
}