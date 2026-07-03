/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/03 12:31:25 by rkaras        #+#    #+#                 */
/*   Updated: 2026/07/03 17:09:41 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>
#include <fstream>

static std::string trim(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	if (start == std::string::npos)
		return "";
	return str.substr(start, end - start + 1);
}

static void processLine(const std::string &line, const BitcoinExchange &exchange)
{
	size_t pos = line.find("|");
	if (pos == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return;
	}
	std::string date = trim(line.substr(0, pos));
	std::string value = trim(line.substr(pos + 1));

	std::chrono::year_month_day cdate;
	if(!exchange.parseDate(date, cdate))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}

	double dvalue;
	try {
		dvalue = std::stod(value);
	} catch (const std::exception &e) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	
	if (dvalue < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return;
	}
	if(dvalue > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return;
	}

	double rate;
	if (!exchange.getRate(cdate, rate))
		std::cerr << "Error: bad input => " << line << std::endl;
	else
		std::cout << date << " => " << dvalue << " = " << dvalue * rate << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}
	
	BitcoinExchange exchange;
	if (!exchange.loadDatabase("data.csv"))
	{
		std::cerr << "Error: database file." << std::endl;
		return EXIT_FAILURE;
	}

	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return EXIT_FAILURE;
	}

	std::string line;
	if (!std::getline(input, line)) //skip the header; fails if file is empty
	{
		std::cerr << "Error: empty file." << std::endl;
		return EXIT_FAILURE;
	}

	while (std::getline(input, line))
		processLine(line, exchange);
	
	return EXIT_SUCCESS;
}