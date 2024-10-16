/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:41:06 by onault            #+#    #+#             */
/*   Updated: 2024/06/12 14:10:02 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}