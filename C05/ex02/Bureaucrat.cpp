/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/27 17:35:12 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/14 18:00:00 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Jane Doe"), _grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	_setGrade(grade);
	std::cout << "Parameterized constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_setGrade(other.getGrade());
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

void	Bureaucrat::_setGrade(int g)
{
	if (g < 1)
		throw GradeTooHighException();
	else if (g > 150)
		throw GradeTooLowException();
	_grade = g;
}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	_setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	_setGrade(_grade + 1);
}

void	Bureaucrat::signForm(AForm &formToSign) const
{
	try
	{
		formToSign.beSigned(*this);
		std::cout << _name <<" signed " << formToSign.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << formToSign.getName() << " because " << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName() << " beacuse " << e.what() << '\n';
	}
	
}

const char	*Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Bureaucrat grade is too high (must be >= 1)");
}

const char	*Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Bureaucrat grade is too low (must be <= 150)");
}


std::ostream &operator<<(std::ostream &output, const Bureaucrat &b)
{
	output	<< b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (output);
}
