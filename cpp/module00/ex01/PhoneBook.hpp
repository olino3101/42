#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>

class Contact {
public:
	void print(int i);
	void print_format(std::string Contact::* memberPtr);
    void askInfo()
    {
       std::cout << "FirstName?" << std::endl;
       std::cin >> firstName;
       std::cout << "LastName?" << std::endl;
       std::cin >> lastName;
       std::cout << "NickName?" << std::endl;
       std::cin >> nickName;
       std::cout << "PhoneNumber?" << std::endl;
       std::cin >> phoneNumber;
       std::cout << "DarkestSecret?" << std::endl;
       std::cin >> darkestSecret;
    }
    void displayContact(const int i)
    {
        std::cout << "Index: " << i << std::endl;
        std::cout << "First Name: " << firstName << std::endl;
        std::cout << "Last Name: " << lastName << std::endl;
        std::cout << "Darkest Secret: " << nickName << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "Darkest Secret: " << darkestSecret << std::endl;
    }
private:
	std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string darkestSecret;
    std::string nickName;
    std::string index;
};
class PhoneBook {
public:
	void doSearch(void);
	void doAdd(int &i);
    PhoneBook() : size(0) {}
private:
	Contact contact[8];
    int size;
};
#endif