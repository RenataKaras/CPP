/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/15 12:53:27 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/15 14:57:44 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"

class	Intern
{	
	public:
		Intern() = default;
		Intern(const Intern& other) = default;
		Intern& operator=(const Intern& other) = default;
		~Intern() = default;
		
		AForm *makeForm(std::string formName, std::string formTarget);

		class FormNameDoesNotExist : public std::exception
		{
			public:
				const char	*what() const noexcept override;
		};
};

#endif /* !INTERN_H */