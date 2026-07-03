/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/03 12:38:04 by rkaras        #+#    #+#                 */
/*   Updated: 2026/07/03 17:25:50 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() : _database() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _database(other._database) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool	BitcoinExchange::parseDate(const std::string &str, std::chrono::year_month_day &out) const
{
	int y, m, d;
	char dash1, dash2;
	std::istringstream ss(str);
	ss >> std::noskipws;
	
	ss >> y >> dash1 >> m >> dash2 >> d;
	if (ss.fail() || dash1 != '-' || dash2 != '-')
		return false;
	
	char leftover;
	if (ss >> leftover)
		return false;
	
	out = std::chrono::year{y} / std::chrono::month{unsigned(m)} / std::chrono::day{unsigned(d)};
	return out.ok();
}

bool	BitcoinExchange::loadDatabase(const std::string &path)
{
	std::ifstream file(path);
	if (!file.is_open())
		return false;

	std::string line;
	if (!std::getline(file, line) || line.empty()) //consumes the "date,exchange rate" header
		return false;
	
	while (std::getline(file, line))
	{
		std::istringstream ss(line);
		std::string date, value;
		std::getline(ss, date, ',');
		std::getline(ss, value);
		
		std::chrono::year_month_day cdate;
		if (!parseDate(date, cdate))
			return false;

		try {
			_database[cdate] = std::stod(value);
		} catch (const std::exception &) {
			return false;
		}
	}
	
	return true;
}

bool BitcoinExchange::getRate(const std::chrono::year_month_day &date, double &out) const
{
	std::map<std::chrono::year_month_day, double>::const_iterator iter = _database.lower_bound(date);
	if (iter != _database.end() && iter->first == date)
	{
		out = iter->second;
		return true;
	}
	if (iter == _database.begin())
		return false;
	--iter;
	out = iter->second;
	return true;
}