/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/22 13:22:08 by rkaras        #+#    #+#                 */
/*   Updated: 2026/06/22 13:22:10 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>


Span::Span() : _maxSize(0), _numVector() {}

Span::Span(unsigned int n) : _maxSize(n), _numVector() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numVector(other._numVector) {}

Span	&Span::operator=(const Span &other) {
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numVector = other._numVector;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int num) {
	if (_numVector.size() >= _maxSize)
		throw std::out_of_range("Maximum numbers filled, no more space\n");
	_numVector.push_back(num);
}

unsigned int	Span::shortestSpan() const {
	if (_numVector.size() < 2)
		throw std::logic_error("Not enough numbers to compute a span\n");

	std::vector<int> sorted(_numVector);
	std::sort(sorted.begin(), sorted.end());
	int shortest =  sorted[1] - sorted[0];
	
	for (size_t i = 1; i < sorted.size(); i++)
		shortest = std::min(shortest, sorted[i] - sorted[i - 1]);
	
	return (shortest);
}

unsigned int	Span::longestSpan() const {
	if (_numVector.size() < 2)
		throw std::logic_error("Not enough numbers to compute a span\n");
	std::vector<int> sorted(_numVector);
	std::sort(sorted.begin(), sorted.end());

	return (sorted.back() - sorted.front());
}

void	Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	if(_numVector.size() + std::distance(first, last) > _maxSize)
		throw std::out_of_range("Not enough space for the range\n");
	_numVector.insert(_numVector.end(), first, last);
}






