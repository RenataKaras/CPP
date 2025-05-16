/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/12 14:27:08 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/16 14:57:38 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
	_rawBits = integer << _fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	_rawBits = static_cast<int>(roundf(number * (1 << _fractionalBits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	_rawBits = other._rawBits;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	_rawBits = other._rawBits;
	
	std::cout << "Copy assignment operator called" << std::endl;
	
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &output, const Fixed &value)
{
	output << value.toFloat();
	return (output);
}

bool	Fixed::operator>(const Fixed &other) const
{
	return (this->_rawBits > other._rawBits);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawBits >= other._rawBits);
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (this->_rawBits < other._rawBits);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawBits <= other._rawBits);
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (this->_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	temp;
	temp._rawBits = _rawBits + other._rawBits;
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	temp;
	temp._rawBits = _rawBits - other._rawBits;
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	temp;
	temp._rawBits = (_rawBits * other._rawBits) >> _fractionalBits;
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	temp;
	temp._rawBits = (_rawBits << _fractionalBits) / other._rawBits;
	return (temp);
}


/*post increment - returns the original value, then increments it*/
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this); //save current value
	_rawBits++;
	return (temp);
}

/*pre increment - increments the value, then returns the new value
it returns a reference because I'm modifying the object itself and that allows for
chaining of operations like ++(++x)*/
Fixed	&Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

/*post decrement*/
Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	_rawBits--;
	return (temp);
}

/*pre decrement*/
Fixed	&Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}