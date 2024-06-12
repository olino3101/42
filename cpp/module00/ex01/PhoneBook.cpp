/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:05:11 by onault            #+#    #+#             */
/*   Updated: 2024/06/12 18:10:46 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


void PhoneBook::doAdd(int &i)
{
    if (i == 8)
    {
		for (int i = 0; i < this->size - 1; i++)
        	this->contact[i] = this->contact[i + 1];
        this->contact[i - 1].askInfo();
    }
    else
    {
        this->contact[i].askInfo();
        this->size++;
        i++;
    }
}

static void printHeader()
{
    for (int i = 0; i < 44; i++)
        std::cout << "_";
    std::cout << std::endl;
    std::cout << "     index|first name|last name|nickname" << std::endl;
    for (int i = 0; i < 44; i++)
        std::cout << "_";
    std::cout << std::endl;
}

void PhoneBook::doSearch()
{ 
    int i;
    
    printHeader();
	for (int i = 0; i < size; i++)
		this->contact[i].print(i);
    while (1)
    {
        std::cout << "wich one?" << std::endl;
        std::cin >> i;
        if (i <= 0 || i > this->size)
            std::cout << "wrong index or you dont have any" << std::endl;
        else
            break ;
    }
    contact[i - 1].displayContact(i);
}