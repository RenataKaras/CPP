/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/07 14:33:10 by rkaras        #+#    #+#                 */
/*   Updated: 2025/05/08 16:31:01 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments! Please use ./replace <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}
	
	FileReplacer replacer(argv[1], argv[2], argv[3]);
	replacer.run();
	return (0);
}