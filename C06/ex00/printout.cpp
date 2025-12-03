/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printout.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/29 12:03:03 by rkaras        #+#    #+#                 */
/*   Updated: 2025/07/30 11:15:13 by rkaras        ########   odam.nl         */
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

void	printConverted(double value, int type)
{
	printChar(value, type);
	printInt(value, type);
	printFloat(value, type);
	printDouble(value, type);
}