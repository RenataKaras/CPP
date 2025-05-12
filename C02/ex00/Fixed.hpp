/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 17:00:21 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/12 13:57:02 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

/* 
first time implementing Orthodox Canonical Form:
	class must explicitly declare, and correctly implement, following member functions:
		1. Default constructor
		2. Copy constructor - creates a new object and initializes it from another object
								of the same type
		3. Copy assignment operator - copy each data member from other into *this and
										return this
		4. Destructor
*/
class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8; //value will always be the integer literal 8
	
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator = (const Fixed &other);
		~Fixed();

		int		getRawBits(void) const; //returns the raw value of the fixed-point value
		void	setRawBits(int const raw); //sets the raw value of the fixed-point number
};

#endif