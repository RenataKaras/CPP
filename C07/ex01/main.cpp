/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/10 13:01:16 by rkaras        #+#    #+#                 */
/*   Updated: 2026/06/10 13:01:18 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printArray(T &element)
{
	std::cout << element << " ";
}

template <typename T>
void addOne(T &element)
{
	element++;
}

int main()
{
	void (*fptr)(int &x) = nullptr;
	int const Carray[4] = {0, 1, 2, 3};
	int array[4] = {0, 1, 2, 3};
	char string[] = "Renata";
	
	::iter(array, 4, fptr);
	
	::iter(Carray, 4, printArray<const int>);
	std::cout << std::endl;

	::iter(array, 4, addOne<int>);
	::iter(array, 4, printArray<int>);
	std::cout << std::endl;

	::iter(string, 6, printArray<char>);
	std::cout << std::endl;
	::iter(string, 6, addOne<char>);
	::iter(string, 6, printArray<char>);
	std::cout << std::endl;

}