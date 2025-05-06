/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 16:18:13 by rkaras        #+#    #+#                 */
/*   Updated: 2025/04/29 16:22:48 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main (int argc, char **argv)
{
	PhoneBook	myBook;
	std::string	input;

	if (argc == 1)
	{
		while (true)
		{
			std::cout << "Please enter ADD, SEARCH or EXIT\n";
			if (!getline(std::cin, input))
				break ;
			if (input == "ADD")
				myBook.addContact();
			else if (input == "SEARCH")
				myBook.searchContact();
			else if (input == "EXIT")
			{
				std::cout << "Exiting PhoneBook\n";
				break ;
			}
			else
				std::cout << "Invalid command, try again\n";
		}
	}
	else
	{
		(void)argv;
		std::cout << "This program does not take arguments\n";
		return (EXIT_FAILURE);
	}
	
	return (EXIT_SUCCESS);
}