/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 12:54:06 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/18 13:36:08 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	typedef AForm *(*FormCreator)(const std::string &);

	/*
	an array of lambda expressions
		- anonymous function object, a way to define a small, nameless function
		on the spot without having to write a separate struct or class
	*/
	static const FormCreator creators[3] = {
		[](const std::string& t) -> AForm *{
			return new ShrubberyCreationForm(t);
		},
		[](const std::string& t) -> AForm *{
			return new RobotomyRequestForm(t);
		},
		[](const std::string& t) -> AForm *{
			return new PresidentialPardonForm(t);
		}
	};
	
	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](formTarget);
		}
	}
	throw FormNameDoesNotExist();
	return nullptr;
}

const char *Intern::FormNameDoesNotExist::what() const noexcept
{
	return ("Form under that name does not exist");
}
