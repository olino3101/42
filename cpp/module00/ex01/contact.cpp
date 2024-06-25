/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:07:03 by onault            #+#    #+#             */
/*   Updated: 2024/06/25 16:58:48 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "contact.hpp"

void Contact::print_format(std::string Contact::* memberPtr)
{
    int len;
    len = (this->*memberPtr).length();
    if (len > 10)
    {
        for (int j = 0; j < 10 - 1; j++)
            std::cout << (this->*memberPtr)[j];
        std::cout << ".";
    }
    else
    {
        std::string space = " ";
        std::cout << std::string(10 - len, space[0]);
        std::cout << this->*memberPtr;
    }
    std::cout << "|";
}

void Contact::displayContact(const int i)
{
    std::cout << "Index: " << i << std::endl;
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Darkest Secret: " << nickName << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

void Contact::askInfo()
{
	std::cout << "FirstName?" << std::endl;
	getline(std::cin, firstName);
	std::cout << "LastName?" << std::endl;
	getline(std::cin, lastName);
	std::cout << "NickName?" << std::endl;
	getline(std::cin, nickName);
	std::cout << "PhoneNumber?" << std::endl;
	getline(std::cin, phoneNumber);
	std::cout << "DarkestSecret?" << std::endl;
	getline(std::cin, darkestSecret);
}

void Contact::print(int i)
{
    this->index = i + 49;
	print_format(&Contact::index);
    print_format(&Contact::firstName);
    print_format(&Contact::lastName);
    print_format(&Contact::nickName);
	std::cout << std::endl;
}

