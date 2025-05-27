/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AAnimal.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/23 13:27:17 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/27 14:28:42 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	AAnimal
{
	protected:
		std::string	_type;
	
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		
		virtual ~AAnimal();

		void		setType(const std::string &type);
		std::string	getType() const;
		
		/* pure virtual function that makes the whole class abstract
		 meaning it cannot be instatianted on its own */
		virtual void		makeSound() const = 0;
};

#endif