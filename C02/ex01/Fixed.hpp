/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 14:23:03 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/12 18:07:30 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	
	public:
		Fixed(); //default
		Fixed(const int integer); //int parameter constructor
		Fixed(const float number); //float parameter constructor
		Fixed(const Fixed &other); //copy constructor
		Fixed &operator=(const Fixed &other); //copy assignment operator, defines what '=' means
		~Fixed(); //deconstructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

/*
ostream = output stream
my own definition of operator<< that knows how to take a Fixed object and write it
into a stream
*/
std::ostream &operator<<(std::ostream &output, const Fixed &value);

#endif