/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 14:36:26 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/06 14:39:33 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombieHeap = newZombie("ZombieHeap");
	zombieHeap->announce();
	delete zombieHeap;
	
	randomChump("ZombieStack");

	return (0);
}