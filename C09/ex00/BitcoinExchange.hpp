/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/07/03 12:24:21 by rkaras        #+#    #+#                 */
/*   Updated: 2026/07/03 16:52:02 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <chrono>

class BitcoinExchange
{
	private:
		std::map<std::chrono::year_month_day, double>	_database;
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

	bool	loadDatabase(const std::string &path);
	bool	getRate(const std::chrono::year_month_day &date, double &out) const;
	bool	parseDate(const std::string &str, std::chrono::year_month_day &out) const;
	
};

#endif /* !BITCOINEXCHANGE_HPP */