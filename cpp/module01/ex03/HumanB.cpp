/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:41:04 by onault            #+#    #+#             */
/*   Updated: 2024/06/12 14:10:16 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(void)
{
    if (this->_weapon != NULL && this->_weapon->getType() != "")
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon" << std::endl;
}

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = NULL;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    this->_weapon = &newWeapon;
}