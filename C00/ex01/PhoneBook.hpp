/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/16 12:04:02 by rkaras        #+#    #+#                 */
/*   Updated: 2025/04/30 12:53:00 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact		_contacts[MAX_CONTACTS];
		int			_count;
		int			_index;
		
		void 		_printSummary() const;
		
	public:
		void		addContact();
		void		searchContact();
		
		PhoneBook();
		~PhoneBook();
} ;

#endif