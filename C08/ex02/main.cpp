/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/06/22 13:23:19 by rkaras        #+#    #+#                 */
/*   Updated: 2026/06/22 14:36:06 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

int main()
{
	std::cout << "===== MutantStack<int> =====" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size after popping one: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	// Same sequence run through a std::list: the output must match the block above.
	std::cout << "===== std::list<int> (same operations) =====" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "List back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size after popping one: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	// MutantStack also works with other element types.
	std::cout << "===== MutantStack<std::string> =====" << std::endl;
	MutantStack<std::string> sstack;
	sstack.push("hello");
	sstack.push("mutant");
	sstack.push("stack");
	std::cout << "top: " << sstack.top() << std::endl;
	std::cout << "size: " << sstack.size() << std::endl;
	for (MutantStack<std::string>::iterator sit = sstack.begin(); sit != sstack.end(); ++sit)
		std::cout << *sit << std::endl;

	return 0;
}
