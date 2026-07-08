/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/08 15:01:36 by rkaras        #+#    #+#                 */
/*   Updated: 2026/07/08 16:20:40 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	RPN rpn;
	int result;
	
	try {
		result = rpn.evaluate(argv[1]);
	} catch(std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	std::cout << result << std::endl;
	return 0;
}