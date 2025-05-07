/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 12:45:39 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/07 14:26:40 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		Weapon		&_weapon;
		std::string	_name;

	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
	
		void	attack();
};


#endif