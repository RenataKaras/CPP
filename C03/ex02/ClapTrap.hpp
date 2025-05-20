/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 12:34:26 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/20 12:03:26 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	/* protected members can be accessed from within the class itself AND from its derived
	classes, but NOT from unrelated code 
	in other words only ClapTrap and its children can touch these */
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		//default
		ClapTrap();
		//parameterized constructor
		ClapTrap(const std::string &name);
		//copy contructor
		ClapTrap(const ClapTrap &other);
		//assignment operator overload
		ClapTrap &operator=(const ClapTrap &other);
		//destructor
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif