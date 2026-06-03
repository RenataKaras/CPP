/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/03/10 16:23:34 by rkaras        #+#    #+#                 */
/*   Updated: 2026/06/03 12:54:18 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
	//default constructor
	Array<int> empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	//constructor with n elements
	Array<int> arr(5);
	std::cout << "arr size: " << arr.size() << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;
	
	//copy construction
	Array<int> copy(arr);
	copy[0] = 999;
	std::cout << "arr[0] after modifying copy: " << arr[0] << std::endl;
	std::cout << "copy[0]: " << copy[0] << std::endl;
	
	//assignment operator
	Array<int> assigned;
	assigned = arr;
	arr[1] = 888;
	std::cout << "assigned[1] after modifying arr: " << assigned[1] << std::endl;
	std::cout << "arr[1]: " << arr[1] << std::endl;

	try {
		arr[150];
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Array<const char *> words(3);
	words[0] = "hello";
	words[1] = "world";
	words[2] = "!";
	for (size_t i = 0; i < words.size(); i++)
		std::cout << words[i] << " ";
	std::cout << std::endl;
	
	return 0;
}