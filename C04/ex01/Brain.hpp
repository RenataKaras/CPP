/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/26 15:15:57 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/27 12:44:23 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class	Brain
{
	private:
		std::string	_ideas[100];
		
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

		const std::string	&getIdea(int i) const;
		void				setIdea(int i, const std::string &idea);
};

#endif