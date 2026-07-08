/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/08 14:51:06 by rkaras        #+#    #+#                 */
/*   Updated: 2026/07/08 16:22:25 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() : _stack() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression)
{
	for (size_t i = 0; i < expression.size(); i++)
	{
		char c = expression[i];
		if (c == ' ')
			continue;
		else if (c >= '0' && c <= '9')
		{
			if (i > 0 && expression[i - 1] >= '0' && expression[i - 1] <= '9')
				throw std::runtime_error("Number bigger than 9");
			_stack.push(c - '0');
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2)
				throw std::logic_error("Less than 2 operands in stack");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			int result;
			
			switch(c)
			{
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if (b == 0)
						throw std::logic_error("Division by zero");
					result = a / b;
					break;
			}
		_stack.push(result);
		}
		else
			throw std::runtime_error("Invalid token");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	return _stack.top();
}