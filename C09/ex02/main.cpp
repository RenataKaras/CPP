/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/08 16:47:19 by rkaras        #+#    #+#                 */
/*   Updated: 2026/07/09 18:53:38 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	PmergeMe p;
	try {
		p.sortAndReport(argc, argv);
	} catch (std::exception &) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}