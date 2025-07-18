/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 15:21:24 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/15 12:45:44 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(std::time(nullptr));
	
	// Valid Bureaucrats
	Bureaucrat high("Alice", 1);
	Bureaucrat mid("Bob", 72);
	Bureaucrat low("Charlie", 150);

	// Create forms
	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robo("Bender");
	PresidentialPardonForm pardon("Homer");

	std::cout << "\n--- Attempting to execute unsigned forms ---\n";
	try {
		shrub.execute(high); 
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n";
	}

	try {
		robo.execute(high);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n";
	}

	try {
		pardon.execute(high);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n--- Signing forms ---\n";
	low.signForm(shrub);	// Should fail
	mid.signForm(shrub);	// Should work
	mid.signForm(robo);		// Should work
	high.signForm(pardon);	// Should work

	std::cout << "\n--- Executing forms with insufficient grade ---\n";
	try {
		low.executeForm(shrub);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n";
	}

	try {
		low.executeForm(robo);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n";
	}

	try {
		mid.executeForm(pardon);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << "\n";
	}

	std::cout << "\n--- Executing forms with proper authority ---\n";
	try {
		mid.executeForm(shrub);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	try {
		for (int i = 0; i < 5; ++i)
			high.executeForm(robo);     // 50% success
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	try {
		high.executeForm(pardon);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n--- Done testing ---\n";

	return (0);
}