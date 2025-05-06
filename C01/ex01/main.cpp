/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 15:21:43 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/06 15:56:58 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int i = 10;
	Zombie *horde;
	
	horde = zombieHorde(i, "chumps");
	
	for (int j = 0; j < i; j++)
	{
		horde[j].announce();
	}
	delete[] horde; //delete[] calls the destructor for each of the N elements in the array in reverse order
	return (0);
}