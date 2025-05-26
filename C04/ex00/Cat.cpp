/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 13:20:55 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/26 14:36:01 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->setType("Cat");
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->setType(other.getType());
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->setType(other.getType());
	std::cout << "Cat assignment operator overload called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}