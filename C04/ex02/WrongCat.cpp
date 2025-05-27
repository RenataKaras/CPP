/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 14:33:49 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/26 15:53:14 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : _brain(new Brain())
{
	this->setType("WrongCat");
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : _brain(new Brain(*other._brain))
{
	this->setType(other.getType());
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->setType(other.getType());
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	std::cout << "WrongCat assignment operator overload called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	delete _brain;
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << std::endl;
}