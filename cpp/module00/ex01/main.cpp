#include "PhoneBook.hpp"

bool verifyCommand(const std::string &command)
{
    if (command == "EXIT")
        exit(0);
    return (command == "ADD" || command == "SEARCH");
}

int main()
{
    PhoneBook phoneBook;
    std::string command;
    int i = 0;
    while (1)
    {
        while (1)
        {
            std::cout << "Enter a command" << std::endl;
            std::cin >> command;
            if (verifyCommand(command) == true)
                break ;
        }
        if (command == "ADD")
            phoneBook.doAdd(i);
        else if (command == "SEARCH")
            phoneBook.doSearch();
    }
}