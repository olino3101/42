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

void printHeader()
{
    for (int i = 0; i < 44; i++)
        cout << "_";
    cout << endl;
    cout << "     index|first name|last name|nickname" << endl;
    for (int i = 0; i < 44; i++)
        cout << "_";
    cout << endl;
}
void print(int i, PhoneBook phoneBook, string Contact::* memberPtr)
{
    int len;
    len = (phoneBook.contact[i].*memberPtr).length();
    if (len > 10)
    {
        for (int j = 0; j < 10 - 1; j++)
            cout << (phoneBook.contact[i].*memberPtr)[j];
        cout << ".";
    }
    else
    {
        string space = " ";
        std::cout << std::string(10 - len, space[0]);
        cout << phoneBook.contact[i].*memberPtr;
    }
    cout << "|";
}
void doSearch(PhoneBook phoneBook)
{
    int i;
    
    printHeader();
    for (int i = 0; i < phoneBook.size; i++)
    {
        phoneBook.contact[i].index = i + 49;
        print(i, phoneBook, &Contact::index);
        print(i, phoneBook, &Contact::firstName);
        print(i, phoneBook, &Contact::lastName);
        print(i, phoneBook, &Contact::nickName);
        cout << endl;
    }
    while (1)
    {
        cout << "wich one?" << endl;
        cin >> i;
        if (i <= 0 || i > phoneBook.size)
            cout << "wrong index or you dont have any" << endl;
        else
            break ;
    }
    phoneBook.contact[i - 1].displayContact(i);
}
int main()
{
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