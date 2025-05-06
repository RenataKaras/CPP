/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 15:07:11 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/06 15:12:56 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return nullptr;
	
	Zombie *horde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	
	return (horde);	
}