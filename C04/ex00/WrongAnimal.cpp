/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 13:59:35 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/26 14:02:14 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal defult constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other.getType())
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
		this->setType(other.getType());
	std::cout << "WrongAnimal assignment operator overload called" <<std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	WrongAnimal::setType(const std::string &type)
{
	_type = type;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Undefined wrong animal sounds" << std::endl;
}