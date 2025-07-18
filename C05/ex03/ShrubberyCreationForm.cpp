/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 17:08:17 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/15 12:24:17 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("home")
{
	std::cout << "Shrubbery default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Shrubbery parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << "Shrubbery copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Shrubbery copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor called" << std::endl;
}

void	ShrubberyCreationForm::executeForm() const
{
	std::ofstream	shrubbery(_target + "_shrubbery");

	if (!shrubbery)
	{
		std::cerr << "Error with creating shrubbery file" << std::endl;
		return ;
	}
	shrubbery << "        *\n"
             "       /|\\\n"
             "      /*|O\\\n"
             "     /*/|\\*\\\n"
             "    /X/O|*\\X\\\n"
             "   /*/X/|\\X\\*\\\n"
             "  /O/*/X|*\\O\\X\\\n"
             "        |X|\n"
             "        |X|\n";
}