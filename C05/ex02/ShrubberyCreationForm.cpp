/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/04 17:08:17 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/14 16:33:29 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("home")
{
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target)
{
	std::cout << "Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
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