/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onault <onault@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:34:53 by onault            #+#    #+#             */
/*   Updated: 2024/06/30 16:14:23 by onault           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{

public:
    void annouce(void);
	Zombie(std::string name);
    ~Zombie();
private:
    std::string name;
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

# endif