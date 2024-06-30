/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:41:17 by onault            #+#    #+#             */
/*   Updated: 2024/06/12 14:09:45 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>
class HumanA
{
public:

    void attack(void);
    HumanA(std::string name, Weapon &weapon);
private:
    std::string _name;
    Weapon& _weapon;
};

#endif