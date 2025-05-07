/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 12:47:23 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/07 14:27:10 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
private:
	Weapon		*_weapon;
	std::string	_name;
	
public:
	HumanB(const std::string &name);
	~HumanB();

	void	attack();
	void	setWeapon(Weapon &weapon);
};

#endif