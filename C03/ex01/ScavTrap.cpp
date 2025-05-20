/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/20 12:04:11 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/20 12:36:49 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "ScavTrap copy constructor called" << std::endl;
}

/* only constructors can use a member-initializer list*/
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap assignment operator called" << std::endl;
	return (*this);
}

/* in destructor you can't call the base-class destructor explicitly from inside the derived-class destructor
the compiler does this for me automatically in the correct order */
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot attack, not enough hit or energy points" << std::endl;
		return ;
	}
	
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage." << std::endl;
	_energyPoints--;
}

void	ScavTrap::guardGate()
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " cannot guard anything, not enough hit or energy points" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " is guarding the gate" << std::endl;
}