/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 15:21:24 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/01 15:58:51 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	{
		Bureaucrat a;
		Bureaucrat b("Lena", 125);
		Bureaucrat c(b);
		Bureaucrat d;
		
		d = c;

		std::cout << a;
		std::cout << b;
		std::cout << c;
		std::cout << d;
	}
	{
		std::cout << std::endl;
		try
		{
			Bureaucrat a("Jan", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		try
		{
			Bureaucrat b("Eduarda", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b("Jan", -45);
			Bureaucrat a("Jan", 154);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			Bureaucrat a("Jan", 1000);
			Bureaucrat b("Jan", 0);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		Bureaucrat a("Jan", 145);
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		a.decrementGrade();
		std::cout << a;
		try
		{
			a.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << std::endl;
		Bureaucrat b("Jan", 6);
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		std::cout << b;
		try
		{
			b.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	return (0);
}