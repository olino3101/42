#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>


using namespace std;

class Contact {
public:
    string firstName;
    string lastName;
    string phoneNumber;
    string darkestSecret;
    string nickName;
    string index;
    void askInfo()
    {
        cout << "FirstName?" << std::endl;
       cin >> firstName;
       cout << "LastName?" << std::endl;
       cin >> lastName;
       cout << "NickName?" << std::endl;
       cin >> nickName;
       cout << "PhoneNumber?" << std::endl;
       cin >> phoneNumber;
       cout << "DarkestSecret?" << std::endl;
       cin >> darkestSecret;
    }
    void displayContact(const int i)
    {
        cout << "Index: " << i << std::endl;
        cout << "First Name: " << firstName << std::endl;
        cout << "Last Name: " << lastName << std::endl;
        cout << "Darkest Secret: " << nickName << std::endl;
        cout << "Phone Number: " << phoneNumber << std::endl;
        cout << "Darkest Secret: " << darkestSecret << std::endl;
    }
};
class PhoneBook {
public:
    Contact contact[8];
    int size;

    PhoneBook() : size(0) {}
};
#endif