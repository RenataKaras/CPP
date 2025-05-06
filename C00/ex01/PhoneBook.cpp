/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 15:04:30 by rkaras        #+#    #+#                 */
/*   Updated: 2025/04/30 12:54:08 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*CONSTRUCTOR & DECONSTRUCTOR*/
PhoneBook::PhoneBook()
{
	_count = 0;
	_index = 0;
	std::cout << "PhoneBook created\n";
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destroyed\n";
}

static bool emptyCheck(const std::string &s)
{
	int i = 0;
	
	if (s.empty())
		return (true);
	
	while (s[i])
	{
		if (isspace(s[i]))
			return (true);
		i++;
	}
	return (false);
}

static std::string formatField(const std::string &s)
{
	if (s.size() > 10)
		return (s.substr(0, 9) + ".");
	else
		return (s);
}

void PhoneBook::addContact()
{
	int index = _index % MAX_CONTACTS;
	std::string responses[5];
	
	std::string prompts[] = {
		"Enter First Name: ",
		"Enter Last Name: ",
		"Enter Nickname: ",
		"Enter Phone Number: ",
		"Enter Darkest Secret: "
	};
	

	for (int i = 0; i < 5; i++)
	{
		std::cout << prompts[i];
		if (!getline(std::cin, responses[i]))
		{
			std::cout << "\nInput aborted. Exiting PhoneBook\n";
			exit(EXIT_FAILURE);
		}
		
		if (emptyCheck(responses[i]))
		{
			std::cout << "The field cannot be empty. Please try again\n";
			--i;
		}
	}
	
	_contacts[index].setFirstName(responses[0]);
	_contacts[index].setLastName(responses[1]);
	_contacts[index].setNickname(responses[2]);
	_contacts[index].setPhoneNumber(responses[3]);
	_contacts[index].setDarkestSecret(responses[4]);
	
	_index++;
	if (_count < MAX_CONTACTS)
		_count++;
}

void PhoneBook::_printSummary() const
{
	std::cout << "+..........+..........+..........+..........+\n";
	
	std::cout << "|" << std::setw(10) << std::right << formatField("Index")
			<< "|" << std::setw(10) << std::right << formatField("First Name")
			<< "|" << std::setw(10) << std::right << formatField("Last Name")
			<< "|" << std::setw(10) << std::right << formatField("Nickname")
			<< "|\n";

	std::cout << "+..........+..........+..........+..........+\n";

	for (int i = 0; i < _count; i++)
	{
		std::cout << "|" << std::setw(10) << std::right << i
				<< "|" << std::setw(10) << std::right << formatField(_contacts[i].getFirstName())
				<< "|" << std::setw(10) << std::right << formatField(_contacts[i].getLastName())
				<< "|" << std::setw(10) << std::right << formatField(_contacts[i].getNickname())
				<< "|\n";
	}
	std::cout << "+..........+..........+..........+..........+\n";
}

void PhoneBook::searchContact()
{
	std::string input;
	int			index;
	
	if (_count <= 0)
	{
		std::cout << "Phonebook is empty, add a contact first\n";
		return ;
	}
	
	_printSummary();

	while (true)
	{
		std::cout << "Enter index of contact to display: ";
		if (!getline(std::cin, input))
			continue ;
		if (input.size() != 1 || !std::isdigit(input[0]))
		{
			std::cout << "Invalid input. Use number 0 to " << _count - 1 << "\n";
			continue ;
		}
		index = std::stoi(input);
		if (index < 0 || index >= _count)
		{
			std::cout << "Index out of range. Use number 0 to " << _count - 1 << "\n";
			continue ;
		}
		break ;
	}
		
		std::cout << "First Name: " << _contacts[index].getFirstName() << "\n"
				<< "Last Name: " << _contacts[index].getLastName() << "\n"
				<< "Nickname: " << _contacts[index].getNickname() << "\n"
				<< "Phone Number: " << _contacts[index].getPhoneNumber() << "\n"
				<< "Darkest Secret: " << _contacts[index].getDarkestSecret() << "\n";
	
}