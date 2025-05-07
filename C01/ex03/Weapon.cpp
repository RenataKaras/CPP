/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 12:55:04 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/07 13:34:13 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
	_type = type;
	std::cout << "Constructor of weapon called" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Deconstructor of weapon called" << std::endl;
}

const std::string &Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(const std::string &newType)
{
	_type = newType;
}