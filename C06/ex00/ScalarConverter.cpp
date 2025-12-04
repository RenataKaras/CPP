/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/22 16:30:10 by rkaras        #+#    #+#                 */
/*   Updated: 2025/12/04 12:19:25 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void	printChar(double value, int type)
{
	std::cout << "char: ";
	if (type == FLOAT_PSEUDO || type == DOUBLE_PSEUDO
		|| value < 0 || value > 127) {
		std::cout << "impossible" << std::endl;
		return ;
	}
	
	if (type == CHAR) {
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
		return ;
	}

	if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;	
}

static void	printInt(double value, int type)
{
	std::cout << "int: ";
	if (type == FLOAT_PSEUDO || type == DOUBLE_PSEUDO
		|| std::isnan(value) || std::isinf(value)
		|| value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max())) {
			std::cout << "impossible" << std::endl;
			return ;
		}
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value, int type)
{
	std::cout << "float: ";
	if (type == FLOAT_PSEUDO || type == DOUBLE_PSEUDO) {
		if (std::isnan(value))
			std::cout << "nanf" << std::endl;
		else if (value == std::numeric_limits<double>::infinity())
			std::cout << "+inff" << std::endl;
		else if (value == -std::numeric_limits<double>::infinity())
			std::cout << "-inff" << std::endl;
		return ;
	}
	
	float f = static_cast<float>(value);
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

static void	printDouble(double value, int type)
{
	std::cout << "double: ";
	if (type == FLOAT_PSEUDO || type == DOUBLE_PSEUDO) {
		if (std::isnan(value))
			std::cout << "nan" << std::endl;
		else if (value == std::numeric_limits<double>::infinity())
			std::cout << "+inf" <<std::endl;
		else if (value == -std::numeric_limits<double>::infinity())
			std::cout << "-inf" << std::endl;
		return ;
	}

	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

static void	printConverted(double value, int type)
{
	printChar(value, type);
	printInt(value, type);
	printFloat(value, type);
	printDouble(value, type);
}
static bool	isChar(const std::string &str)
{
	if (str.length() == 1 &&
	std::isprint(static_cast<unsigned char>(str[0])) &&
	!std::isdigit(static_cast<unsigned char>(str[0])))
	{
		return (true);
	}
	return (false);
}

static bool	isPseudoLiteralFloat(const std::string &str)
{
	if (str == "-inff" ||
		str == "+inff" ||
		str == "nanf")
			return (true);
	return (false);
}

static bool	isPseudoLiteralDouble(const std::string &str)
{
	if (str == "-inf" ||
		str == "+inf" ||
		str == "nan")
			return (true);
	return (false);
}

static double	convertPseudoValue(const std::string &str, const int &type)
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

static bool	isInt(const std::string &str)
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

static bool	isFloat(const std::string &str)
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

static bool	isDouble(const std::string &str)
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

void ScalarConverter::convert(const std::string &literal)
{
	
	double	value;
	int		type;
	
	if (isChar(literal)) {
		value = static_cast<double>(literal[0]);
		type = CHAR;
	}
	else if (isInt(literal)) {
		type = INT;
		value = static_cast<double>(std::stoi(literal));
	}
	else if (isFloat(literal)) {
		type = FLOAT;
		value = static_cast<double>(std::stof(literal));
	}
	else if (isPseudoLiteralFloat(literal)) {
		type = FLOAT_PSEUDO;
		value = convertPseudoValue(literal, type);
	}
	else if (isPseudoLiteralDouble(literal)) {
		type = DOUBLE_PSEUDO;
		value = convertPseudoValue(literal, type);
	}
	else if (isDouble(literal)) {
		type = DOUBLE;
		value = std::stod(literal);
	}
	else {
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	
	printConverted(value, type);
}