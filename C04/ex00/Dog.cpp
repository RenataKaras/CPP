/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 12:50:30 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/26 13:48:19 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->setType("Dog");
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
	this->setType(other.getType());
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->setType(other.getType());
	std::cout << "Dog assignment operator overload called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}