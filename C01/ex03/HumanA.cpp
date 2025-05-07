/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 13:14:31 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/07 14:26:48 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _weapon(weapon), _name(name)
{
	std::cout << "HumanA constructor called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA deconstructor called" << std::endl;
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
