/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 12:34:26 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/19 14:53:02 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	private:
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