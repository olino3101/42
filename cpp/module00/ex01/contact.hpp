#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
public:
	void print(int i);
	void print_format(std::string Contact::* memberPtr);
    void askInfo();
    void displayContact(const int i);
private:
	std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string darkestSecret;
    std::string nickName;
    std::string index;
};

#endif