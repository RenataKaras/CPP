/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/04 14:38:26 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/04 15:50:30 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <ctime>

class Base
{
	public:
		virtual ~Base() = default;
};

Base *generate(void); // randomly instatiates A, B or C and returns the instance as a Base pointer
void identify(Base *p); // prints the actual type of the object pointed to by p
void identify(Base &p); //prints the actual type of the object referenced by p

/*
*dynamic_cast*
	- only this cast can safely check the real type of a polymorphic object
		- because it uses RTTI(Run-Time Type Information) to check real types 
	- only this cast can cast a Base * to the correct derived class
	- can detect if the cast is valid
*/

#endif /* !BASE_H */