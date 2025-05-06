/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 14:47:52 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/06 15:21:02 by rkaras        ########   odam.nl         */
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
		Zombie(); //default contructor
		~Zombie();
		
		void	announce(void);
		void	setName(std::string name);
		
};

Zombie	*zombieHorde(int N, std::string name);

#endif