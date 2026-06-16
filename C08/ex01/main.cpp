#include "Span.hpp"
#include <iostream>

int main()
{
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
	
	return 0;
}