/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/06 16:39:51 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/06 16:49:14 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>


int main(void)
{
	std::string	Str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &Str;
	std::string	&stringREF = Str;

	std::cout << "Address of Str: " << &Str << std::endl;
	std::cout << "Address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of Str: " << Str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	
	return (0);
}
