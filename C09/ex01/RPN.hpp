/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/08 14:45:48 by rkaras        #+#    #+#                 */
/*   Updated: 2026/07/08 14:50:03 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		int	evaluate(const std::string &expression);
};

#endif /* !RPN_H */