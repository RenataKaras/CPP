/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 13:22:31 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/07 13:28:53 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
{
	_name = name;
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB deconstructor called" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack() const
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapon" << std::endl;
}