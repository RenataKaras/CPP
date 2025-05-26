/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/23 13:32:43 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/26 13:44:43 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* in constructors we use direct assignment */
Animal::Animal() : _type("Animal")
{
	std::cout << "Animal defult constructor called" << std::endl;
}

/* using a getter here to respect the encapsulation from another object, but assgining directly
to my own _type */
Animal::Animal(const Animal &other) : _type(other.getType())
{
	std::cout << "Animal copy constructor called" << std::endl;
}

/* using a setter here because the object is already constructed and I'm modifying its state */
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->setType(other.getType());
	std::cout << "Animal assignment operator overload called" <<std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::setType(const std::string &type)
{
	_type = type;
}

std::string Animal::getType() const
{
	return (_type);
}

void	Animal::makeSound() const
{
	std::cout << "Undefined animal sounds" << std::endl;
}