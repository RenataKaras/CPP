/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/08 16:50:51 by rkaras        #+#    #+#                 */
/*   Updated: 2026/07/15 15:56:04 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdexcept>
#include <iostream>
#include <algorithm> //lower_bound + min
#include <chrono>
#include <string>
#include <utility> //for pairs
#include <cmath> //only for the commented-out fjOptimal below

PmergeMe::PmergeMe() : _vector(), _deque() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				throw std::runtime_error("Not a positive number");
		}
		int number = std::stoi(argv[i]);
		_vector.push_back(number);
		_deque.push_back(number);
	}
}

template <typename T>
static void printContainer(const std::string &str, const T &container)
{
	std::cout << str;
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

//comparison counter, for verifying optimality: uncomment this block, the
//++g_cmp lines below and the prints in sortAndReport. The theoretical
//Ford-Johnson worst case is F(n) = sum_{k=1}^{n} ceil(log2(3k/4)).
//static long g_cmp = 0;
//static long fjOptimal(size_t n)
//{
//	long sum = 0;
//	for (size_t k = 1; k <= n; k++)
//		sum += (long)std::ceil(std::log2(3.0 * k / 4.0));
//	return sum;
//}

static bool compareByFirst(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	//++g_cmp;
	return a.first < b.first;
}

static std::vector<size_t> jacobsthalUpTo(size_t n)
{
	//1, 3, 5, 11, 21, 43, ...
	std::vector<size_t> temp;
	temp.push_back(1);
	temp.push_back(3);
	while (temp.back() < n)
		temp.push_back(temp[temp.size() - 1] + 2 * temp[temp.size() - 2]);
	return temp;
}

template <typename C>
static void mergeInsert(C &elems)
{
	size_t n = elems.size();
	if (n <= 1)
		return;

	//step 1: pairwise comparisons; winner and loser stay bonded via the same index
	C	winners;
	C	losers;
	C	keys;

	for (size_t i = 0; i + 1 < n; i += 2)
	{
		//++g_cmp;
		if (elems[i].first > elems[i + 1].first)
		{
			winners.push_back(elems[i]);
			losers.push_back(elems[i + 1]);
		}
		else
		{
			winners.push_back(elems[i + 1]);
			losers.push_back(elems[i]);
		}
		keys.push_back(std::make_pair(winners.back().first, (int)(winners.size() - 1)));
	}
	bool odd = (n % 2 != 0);
	std::pair<int, int> extra;
	if (odd)
		extra = elems[n - 1];

	//step 2: sort the winners by merge insertion; each key drags its bond index along,
	mergeInsert(keys);

	//step 3: lay out b1 + all winners, then Jacobsthal binary insert the losers
	C main;
	size_t m = keys.size();
	std::vector<size_t> bpos(m + 1); //bpos[j] = will be keeping the live index of winner a_j in main

	main.push_back(losers[keys[0].second]);
	for (size_t j = 0; j < m; j++)
	{
		main.push_back(winners[keys[j].second]);
		bpos[j + 1] = j + 1;
	}

	size_t numPend = m + (odd ? 1 : 0); //number of all of loosers + extra that need to be inserted
	std::vector<size_t> jacob = jacobsthalUpTo(numPend);
	size_t prev = 1; //b1 is already placed
	for (size_t i = 1; i < jacob.size() && prev < numPend; i++)
	{
		size_t groupEnd = std::min(jacob[i], numPend);
		for (size_t j = groupEnd; j > prev; j--)
		{
			std::pair<int, int> val;
			size_t bound;
			if (j > m) //the odd extra: no partner, so search the whole chain
			{
				val = extra;
				bound = main.size();
			}
			else //a real loser: search only left of its bonded winner
			{
				val = losers[keys[j - 1].second];
				bound = bpos[j];
			}
			typename C::iterator pos = std::lower_bound(main.begin(), main.begin() + bound, val, compareByFirst);
			size_t insIdx = pos - main.begin();
			main.insert(pos, val);

			for (size_t k = 1; k <= m; k++)
				if (bpos[k] >= insIdx)
					bpos[k]++;
		}
		prev = groupEnd;
	}
	elems = main;
}

void PmergeMe::sortVector()
{
	std::vector<std::pair<int, int>> elems;
	for (size_t i = 0; i < _vector.size(); i++)
		elems.push_back(std::make_pair(_vector[i], 0));

	mergeInsert(elems);

	for (size_t i = 0; i < elems.size(); i++)
		_vector[i] = elems[i].first;
}

void PmergeMe::sortDeque()
{
	std::deque<std::pair<int, int>> elems;
	for (size_t i = 0; i < _deque.size(); i++)
		elems.push_back(std::make_pair(_deque[i], 0));

	mergeInsert(elems);

	for (size_t i = 0; i < elems.size(); i++)
		_deque[i] = elems[i].first;
}

void PmergeMe::sortAndReport(int argc, char **argv)
{
	auto start = std::chrono::steady_clock::now();
	parseArgs(argc, argv);
	auto end = std::chrono::steady_clock::now();
	double parseTime = std::chrono::duration<double, std::micro>(end - start).count();

	printContainer("Before: ", _vector);

	//vector
	//g_cmp = 0;
	start = std::chrono::steady_clock::now();
	sortVector();
	end = std::chrono::steady_clock::now();
	double vTime = parseTime + std::chrono::duration<double, std::micro>(end - start).count();
	//std::cout << "vector comparisons: " << g_cmp << " (optimal F(n) = " << fjOptimal(_vector.size()) << ")" << std::endl;

	//deque
	//g_cmp = 0;
	start = std::chrono::steady_clock::now();
	sortDeque();
	end = std::chrono::steady_clock::now();
	double dTime = parseTime + std::chrono::duration<double, std::micro>(end - start).count();
	//std::cout << "deque comparisons: " << g_cmp << " (optimal F(n) = " << fjOptimal(_deque.size()) << ")" << std::endl;

	printContainer("After: ", _vector);

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << vTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : " << dTime << " us" << std::endl;
}
