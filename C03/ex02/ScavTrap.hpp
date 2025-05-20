/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 15:16:09 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/20 12:03:17 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		//default
		ScavTrap();
		//parameterized constructor
		ScavTrap(const std::string &name);
		//copy constructor
		ScavTrap(const ScavTrap &other);
		//assignment operator overload
		ScavTrap &operator=(const ScavTrap &other);
		//destructor
		~ScavTrap();

		void	attack(const std::string &target);
		void	guardGate();
		
	
};

#endif
