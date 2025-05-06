/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 14:24:37 by rkaras        #+#    #+#                 */
/*   Updated: 2025/04/28 14:07:28 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		std::string	_firstName,
					_lastName,
					_nickname,
					_phoneNumber,
					_darkestSecret;

	public:
		//constructor - initialising the object
		Contact();
		//deconstructor
		~Contact();

		//setters
		
		/*they're receiving arguments as references
		REFERENCE is just an alias for the original object and any operations on it act as
		on the original.
		Once initialised it always refers to that same object.
		It cannot be NULL, so there must be a valid object it references*/
		void setFirstName(const std::string &firstName);
		void setLastName(const std::string &lastName);
		void setNickname(const std::string &nickname);
		void setPhoneNumber(const std::string &phoneNumber);
		void setDarkestSecret(const std::string &darkestSecret);

		//getters
		/*const after the function means that the function promises no to change the object*/
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
} ;

#endif
