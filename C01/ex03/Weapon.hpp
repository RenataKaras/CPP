/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 12:41:19 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/07 13:34:00 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class	Weapon
{
	private:
		std::string _type;
	
	public:
		Weapon(const std::string &type);
		~Weapon();

		const std::string	&getType() const;
		void				setType(const std::string &newType);
};

#endif
