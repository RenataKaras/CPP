/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   typeChecks.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/29 11:52:59 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/03 16:33:58 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	isChar(const std::string &str)
{
	if (str.length() == 1 &&
	std::isprint(static_cast<unsigned char>(str[0])) &&
	!std::isdigit(static_cast<unsigned char>(str[0])))
	{
		return (true);
	}
	return (false);
}

bool	isPseudoLiteralFloat(const std::string &str)
{
	if (str == "-inff" ||
		str == "+inff" ||
		str == "nanf")
			return (true);
	return (false);
}

bool	isPseudoLiteralDouble(const std::string &str)
{
	if (str == "-inf" ||
		str == "+inf" ||
		str == "nan")
			return (true);
	return (false);
}

double	convertPseudoValue(const std::string &str, const int &type)
{
	double	value;
	
	if (type == FLOAT_PSEUDO) {
		if (str == "-inff")
			value = -std::numeric_limits<float>::infinity();
		else if (str == "+inff")
			value = std::numeric_limits<float>::infinity();
		else
			value = std::numeric_limits<float>::quiet_NaN();		
	}
	
	if (type == DOUBLE_PSEUDO) {
		if (str == "-inf")
			value = -std::numeric_limits<double>::infinity();
		else if (str == "+inf")
			value = std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::quiet_NaN();
	}
	
	return (value);
}

bool	isInt(const std::string &str)
{
	if (str.empty())
		return (false);

	size_t i = 0;
	
	if (str[i] == '+' || str[i] == '-')
		i++;
	
	if (i >= str.length() || !std::isdigit(str[i]))
		return (false);

	for (; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}

	long long val = std::stoll(str);
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
			return false;

	return (true);
}

bool	isFloat(const std::string &str)
{
	if (str.length() < 2 || str.back() != 'f')
		return (false);
	
	std::string withoutF = str.substr(0, str.length() - 1);
	size_t i = 0;
	bool hasDot = false;

	if (withoutF[i] == '+' || withoutF[i] == '-')
		i++;
		
	if (i >= withoutF.length())
		return (false);

	for (; i < withoutF.length(); i++) {
		if (withoutF[i] == '.') {
			if (hasDot == true)
				return (false);
			hasDot = true;
		}
		else if (!std::isdigit(withoutF[i]))
			return (false);
	}
	return (hasDot);
}

bool	isDouble(const std::string &str)
{
	if (str.empty() || str.find('f') != std::string::npos)
		return (false);
	
	size_t i = 0;
	bool hasDot = false;

	if (str[i] == '-' || str[i] == '+')
		i++;
		
	if (i >= str.length())
		return (false);
	
	for (; i < str.length(); i++) {
		if (str[i] == '.') {
			if (hasDot == true)
				return (false);
			hasDot = true;
		}
		else if (!std::isdigit(str[i]))
			return(false);
	}
	return (hasDot);
}