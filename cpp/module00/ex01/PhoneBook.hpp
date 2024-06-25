#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include "contact.hpp"

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