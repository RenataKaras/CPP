/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 15:21:24 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/04 14:41:17 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Form a("Unknown form", 160, 10);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		try
		{
			Form b ("Unknown form", -1, 10);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		try
		{
			Form c("Unknown form", 10, 160);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}

		try
		{
			Form d("Unknown form", 10, -1);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	
	{
		Form a("Passport", 95, 10);
		
		std::cout << a;

		Bureaucrat b("Lena", 96);
		
		try
		{
			a.beSigned(b);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			std::cout << "won't work" << '\n';
		}
		catch(Form::GradeTooLowException &e)
		{
			std::cout << "will work" << "\n";
		}

		b.incrementGrade();
		std::cout << b;
		a.beSigned(b);
		std::cout << a;
	}
	
	{
		Form a("Death row pardon", 80, 60);
		Bureaucrat b ("Renata", 81);
		b.signForm(a);
		b.incrementGrade();
		b.signForm(a);
		std::cout << a;
	}
	
	return (0);
}