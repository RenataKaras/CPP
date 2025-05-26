/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/23 13:27:17 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/26 13:36:22 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal
{
	protected:
		std::string	_type;
	
	public:
		//default
		Animal();
		//copy constructor
		Animal(const Animal &other);
		//assignment operator overload
		Animal &operator=(const Animal &other);
		
		//destructor - polymorphic base classes MUST always have virtual destructor
		/* when we delete an object through a pointer to a base class, C++ will call
		the base's destructor, and only that one, UNLESS that destructor is marked
		virtual */
		virtual ~Animal();

		void		setType(const std::string &type);
		std::string	getType() const;
		
		/* a VIRTUAL function in base class tells the compiler: "when called through
		a pointer or a reference to this base, dispatch to the MOST-DERRIVED override" */
		virtual void		makeSound() const;
};

#endif