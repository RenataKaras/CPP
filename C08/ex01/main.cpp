/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/22 13:22:24 by rkaras        #+#    #+#                 */
/*   Updated: 2026/06/22 13:22:27 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	
	std::srand(std::time(NULL));
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span big(10000);
	std::vector<int> temp;
	for (int i = 0; i < 10000; i++)
		temp.push_back(rand());
	big.addRange(temp.begin(), temp.end());
	std::cout << "shortest: " << big.shortestSpan() << std::endl;
	std::cout << "longest: " << big.longestSpan() << std::endl;

	// Exception: adding past capacity.
	std::cout << "--- error cases ---" << std::endl;
	try
	{
		Span full(2);
		full.addNumber(1);
		full.addNumber(2);
		full.addNumber(3);
	}
	catch (const std::exception& e)
	{
		std::cerr << "caught: " << e.what();
	}

	// Exception: not enough numbers to compute a span.
	try
	{
		Span tooFew(5);
		tooFew.addNumber(42);
		tooFew.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cerr << "caught: " << e.what();
	}

	return 0;
}