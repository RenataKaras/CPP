/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/23 13:32:43 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/27 14:32:25 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal")
{
	std::cout << "AAnimal defult constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other.getType())
{
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->setType(other.getType());
	std::cout << "AAnimal assignment operator overload called" <<std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

void	AAnimal::setType(const std::string &type)
{
	_type = type;
}

std::string AAnimal::getType() const
{
	return (_type);
}

void	AAnimal::makeSound() const
{
	std::cout << "Undefined animal sounds" << std::endl;
}