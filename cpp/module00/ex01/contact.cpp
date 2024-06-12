/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:07:03 by onault            #+#    #+#             */
/*   Updated: 2024/06/12 18:13:25 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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

void Contact::print(int i)
{
    this->index = i + 49;
	print_format(&Contact::index);
    print_format(&Contact::firstName);
    print_format(&Contact::lastName);
    print_format(&Contact::nickName);
	std::cout << std::endl;
}

