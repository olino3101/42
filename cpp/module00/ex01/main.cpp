#include "PhoneBook.hpp"

using namespace std;

bool verifyCommand(const string &command)
{
    if (command == "EXIT")
        exit(0);
    return (command == "ADD" || command == "SEARCH");
}

void orderContacts(PhoneBook &phoneBook)
{
    for (int i = 0; i < phoneBook.size - 1; i++)
        phoneBook.contact[i] = phoneBook.contact[i + 1];
}

void doAdd(PhoneBook &phoneBook, int &i)
{
    // watch out si yen a plus que 8 ca doit pas marcher
    if (i == 8)
    {
        orderContacts(phoneBook);
        phoneBook.contact[i - 1].askInfo();
        
    }
    else
    {
        phoneBook.contact[i].askInfo();
        phoneBook.size++;
        i++;
    }
}

void doSearch(PhoneBook phoneBook)
{
    for (int i = 0;  i < phoneBook.size; i++)
        phoneBook.contact[i].displayContact(i + 1);
}
int main()
{
    // peut etre faire un while a linfini
    PhoneBook phoneBook;
    string command;
    int i = 0;
    phoneBook.size = 0;
    while (1)
    {
        while (1)
        {
            cout << "Enter a command" << endl;
            cin >> command;
            if (verifyCommand(command) == true)
                break ;
        }
        if (command == "ADD")
            doAdd(phoneBook, i);
        else if (command == "SEARCH")
            doSearch(phoneBook);
    }
}