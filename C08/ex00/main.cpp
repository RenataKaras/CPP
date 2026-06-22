/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/22 13:22:37 by rkaras        #+#    #+#                 */
/*   Updated: 2026/06/22 13:22:39 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> vector = {5, 10, 15, 20};
	try
	{
		std::vector<int>::iterator it = ::easyfind(vector, 10);
		std::cout << "Value found is " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		::easyfind(vector, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::list<int> list = {25, 30, 35, 40};
	try
	{
		std::list<int>::iterator it = ::easyfind(list, 35);
		std::cout << "Value found is " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		::easyfind(list, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
	
	return 0;
}
