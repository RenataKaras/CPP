/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 13:59:42 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/20 14:37:34 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		//default
		FragTrap();
		//parameterized construtctor
		FragTrap(const std::string &name);
		//copy constructor
		FragTrap(const FragTrap &other);
		//assignment operator overload
		FragTrap &operator=(const FragTrap &other);
		//destructor
		~FragTrap();

		void	highFivesGuys(void);
};

#endif