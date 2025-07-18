/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 18:18:32 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/15 12:12:40 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Unknown form"), _signGrade(150), _execGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_checkGrades();
	std::cout << "Parameterized constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
}

void	Form::_checkGrades() const
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSign() const
{
	return (_signed);
}

int	Form::getSignGrade() const
{
	return (_signGrade);
}

int	Form::getExecGrade() const
{
	return (_execGrade);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _signGrade)
		_signed = true;
	else if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &output, const Form &f)
{
	output << "Form name: " << f.getName() << std::endl \
			<< "Sign grade: " << f.getSignGrade() << std::endl \
			<< "Execution grade: " << f.getExecGrade() << std::endl \
			<< "Signature status: " << f.getSign() << std::endl;
	return (output);
}