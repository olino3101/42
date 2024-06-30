/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:41:23 by onault            #+#    #+#             */
/*   Updated: 2024/06/12 14:09:41 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
public:

    void setWeapon(Weapon &newWeapon);
    void attack(void);
    HumanB(std::string name);
private:

    std::string _name;
    Weapon *_weapon;
};

#endif