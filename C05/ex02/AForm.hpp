/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 18:02:04 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/04 15:45:04 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class	AForm
{
	private:
		const std::string	_name;
		bool				_signed = false;
		const int			_signGrade;
		const int			_execGrade;

		void				_checkGrades() const;
	
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const Form &other);
		AForm &operator=(const Form &other);
		virtual ~AForm();

		std::string getName() const;
		bool		getSign() const;
		int	getSignGrade() const;
		int	getExecGrade() const;

		void beSigned(const Bureaucrat &b);
		
		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const noexcept override;
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &output, const Form &f);

#endif