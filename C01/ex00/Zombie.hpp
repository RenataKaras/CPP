/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 13:54:24 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/06 14:48:55 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	_name;
		
	public:
		Zombie(std::string name);
		~Zombie();
		
		void	announce(void);
};
	
Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
	
#endif