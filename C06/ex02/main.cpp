/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/04 15:43:18 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/04 15:53:47 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void) {
	std::srand(std::time(NULL));

	Base *p = generate();
	identify(p);
	identify(*p);

	Base *wrong = nullptr;
	identify(wrong);
	identify(*wrong);

	delete p;
}