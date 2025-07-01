/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/27 15:58:03 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/01 15:30:52 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class	Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		
		void	_setGrade(int g);
	
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;
		
		void		incrementGrade();
		void		decrementGrade();

		
		/* 
		- noexcept means that this function is not supposed to propagate exceptions
		- if an exception does escape, the runtime calls std::terminate, aborting the program
		*/
		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const noexcept;
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const noexcept;
		};
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b);

#endif