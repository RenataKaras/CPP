/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/07 13:17:21 by rkaras        #+#    #+#                 */
/*   Updated: 2025/04/29 17:07:32 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			for (int j = 0; static_cast<size_t>(j) < arg.length(); j++)
			{
				std::cout << static_cast<char>(toupper(arg[j]));
			}
		}
	}
	std::cout << std::endl;
	return (0);
}
