/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:31:33 by rkaras        #+#    #+#                 */
/*   Updated: 2025/04/23 16:48:01 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*CONSTRUCTOR & DECONSTRUCTOR*/
Contact::Contact()
{
	_firstName = "";
	_lastName = "";
	_nickname = "";
	_darkestSecret = "";
	_phoneNumber = "";

	std::cout << "Contact created\n";
}

Contact::~Contact()
{
	std::cout << "Contact destroyed\n";
}


/*SETTERS*/
void Contact::setFirstName(const std::string &firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	_phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	_darkestSecret = darkestSecret;
}

/*GETTERS*/
std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}
