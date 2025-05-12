/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 17:00:21 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/08 17:03:23 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_numberFixedPoint;
		static const int	_numberFractional;
	
	public:
		Fixed();
		~Fixed();
};

#endif