/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 18:18:32 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/09 15:45:15 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Unknown form"), _signGrade(150), _execGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	_checkGrades();
	std::cout << "Parametirized constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

void	AForm::_checkGrades() const
{
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSign() const
{
	return (_signed);
}

int	AForm::getSignGrade() const
{
	return (_signGrade);
}

int	AForm::getExecGrade() const
{
	return (_execGrade);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _signGrade)
		_signed = true;
	else if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade is too low");
}

const char	*AForm::FormNotSignedException::what() const noexcept
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &output, const AForm &f)
{
	output << "Form name: " << f.getName() << std::endl \
			<< "Sign grade: " << f.getSignGrade() << std::endl \
			<< "Execution grade: " << f.getExecGrade() << std::endl \
			<< "Signature status: " << f.getSign() << std::endl;
	return (output);
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (_signed == false)
		throw FormNotSignedException();
	if (_execGrade < executor.getGrade())
		throw GradeTooLowException();
	executeForm();
}
