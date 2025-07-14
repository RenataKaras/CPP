/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 18:02:04 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/14 18:14:17 by rkaras        ########   odam.nl         */
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
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		
		std::string getName() const;
		bool		getSign() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		
		void			beSigned(const Bureaucrat &b);
		void			execute(const Bureaucrat &executor) const;
		virtual void	executeForm() const = 0;
		
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

		class	FormNotSignedException : public std::exception
		{
			public:
				const char	*what() const noexcept override;
		};

		
};

std::ostream &operator<<(std::ostream &output, const AForm &f);

#endif