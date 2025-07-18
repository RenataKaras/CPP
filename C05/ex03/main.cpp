/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/01 15:21:24 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/18 14:40:32 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::srand(std::time(nullptr));

	Intern	randomIntern;

	std::cout << "***Intern creating forms***\n";
	AForm	*shrub = randomIntern.makeForm("shrubbery creation", "Courtyard");
	AForm	*robo = randomIntern.makeForm("robotomy request", "Mislav");
	AForm	*pardon = randomIntern.makeForm("presidential pardon", "Slobodan");
	AForm	*invalid = nullptr;
	
	try {
		invalid = randomIntern.makeForm("doesn't exist", "office");
	}
	catch(const std::exception& e) {
		std::cout << e.what() << '\n';
	}
	
	std::cout << "***Creating Bureaucrats***\n";
	Bureaucrat high("Ana", 1);	//can sign and execute anything
	Bureaucrat mid("Zora", 45);	//can execute robotomy
	Bureaucrat low("Fran", 150);//can't sign or execute anything

	std::cout << "***Signing forms***\n";
	high.signForm(*shrub);
	high.signForm(*robo);
	high.signForm(*pardon);

	std::cout << "***Executing forms***\n";
	high.executeForm(*shrub);
	for (int i = 0; i < 5; i++) {
		mid.executeForm(*robo);
	}
	high.executeForm(*pardon);

	std::cout << "***Low grade bureaucrat tries thigns***\n";
	low.signForm(*shrub);
	low.executeForm(*pardon);

	std::cout << "***Cleaning***\n";
	delete shrub;
	delete robo; 
	delete pardon;
	delete invalid;
	
	return (0);
}