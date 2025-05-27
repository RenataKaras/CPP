/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 13:20:55 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/27 14:42:33 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	this->setType("Cat");
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : _brain(new Brain(*other._brain))
{
	this->setType(other.getType());
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "Cat assignment operator overload called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return(_brain);
}