/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/04 15:23:21 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/04 15:48:35 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int r = std::rand() % 3;
	
	switch (r) {
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
}

//if pointer cast doesn't work it returns a nullptr
void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

//if reference cast doesn't work it throws std::bad_cast
void identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (...) {}
	
	std::cout << "Unknown type" << std::endl;	
}