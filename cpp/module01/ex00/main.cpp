/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:34:38 by onault            #+#    #+#             */
/*   Updated: 2024/06/27 14:05:03 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    std::cout << "with new " << std::endl;
    Zombie *zombi = newZombie("zombie 1");
    zombi->annouce();
    delete zombi;

    std::cout << "with not new " << std::endl;
    randomChump("zombie 2");

    return 0;
}