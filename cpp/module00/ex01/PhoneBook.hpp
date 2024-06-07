#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>


using namespace std;

class Contact {
public:
    string firstName;
    string lastName;
    long int phoneNumber;
    string darkestSecret;

    void askInfo()
    {
        cout << "firstName?" << std::endl;
       cin >> firstName;
      //  cout << "LastName?" << std::endl;
      //  cin >> lastName;
      //  cout << "phoneNumber?" << std::endl;
      //  cin >> phoneNumber;
      //  cout << "darkestSecret?" << std::endl;
      //  cin >> darkestSecret;
    }
    void displayContact(const int i)
    {
        cout << "Index: " << i << std::endl;
        cout << "First Name: " << firstName << std::endl;
        //cout << "Last Name: " << lastName << std::endl;
        //cout << "Phone Number: " << phoneNumber << std::endl;
        //cout << "Darkest Secret: " << darkestSecret << std::endl;
    }
};
class PhoneBook {
public:
    Contact contact[8];
    int size;

    PhoneBook() : size(0) {}
};
#endif