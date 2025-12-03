/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 16:31:37 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/22 16:33:52 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return EXIT_FAILURE;
	}
	
	ScalarConverter::convert(argv[1]);
	return EXIT_SUCCESS;
}